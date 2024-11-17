#include "EspecialidadController.h"

using namespace SistemaHospitalController;
using namespace System::IO; //Para leer archivos
using namespace System::Runtime::Serialization::Formatters::Binary;

EspecialidadController::EspecialidadController() {

}

// Método para listar especialidades
List<Especialidad^>^ EspecialidadController::listarEspecialidades() {
    List<Especialidad^>^ listaEspecialidades = gcnew List<Especialidad^>();
    array<String^>^ lineasArchivo = File::ReadAllLines("Especialidades.txt");
    String^ separadores = ";";
    for each (String ^ linea in lineasArchivo) {
        /*Voy a separar los datos de una linea en un arreglo de string*/
        array<String^>^ datos = linea->Split(separadores->ToCharArray());
        //Clase Especialidad
        int idEspecialidad = Convert::ToInt32(datos[0]);
        String^ nombre = datos[1];
        String^ descripcion = datos[2];

        // Crear objeto Especialidad y añadir a la lista
        Especialidad^ especialidad = gcnew Especialidad();
        // Asignar propiedades de Especialidad
        especialidad->setIdEspecialidad(idEspecialidad);
        especialidad->setNombre(nombre);
        especialidad->setDescripcion(descripcion);

        listaEspecialidades->Add(especialidad);
    }
    return listaEspecialidades;
}

// Método para buscar especialidades por id
Especialidad^ EspecialidadController::buscarEspecialidadById(int idEspecialidad) {
    List<Especialidad^>^ listaEspecialidades = listarEspecialidades();
    Especialidad^ especialidadEncontrado = gcnew Especialidad();
    for each (Especialidad ^ especialidad in listaEspecialidades) {
        if (especialidad->getIdEspecialidad() == idEspecialidad) {
            // Verificar por ID de especialidad
            especialidadEncontrado->setIdEspecialidad(especialidad->getIdEspecialidad());
            especialidadEncontrado->setNombre(especialidad->getNombre());
            especialidadEncontrado->setDescripcion(especialidad->getDescripcion());
            break;
        }
    }
    return especialidadEncontrado;
}

// Método para buscar especialidades por nombr
Especialidad^ EspecialidadController::buscarEspecialidadByNombre(String^ sNombre) {
    List<Especialidad^>^ listaEspecialidades = listarEspecialidades();
    Especialidad^ especialidadEncontrado = gcnew Especialidad();
    for each (Especialidad ^ especialidad in listaEspecialidades) {
        if (especialidad->getNombre()->Equals(sNombre)) {
            // Verificar por ID de especialidad
            especialidadEncontrado->setIdEspecialidad(especialidad->getIdEspecialidad());
            especialidadEncontrado->setNombre(especialidad->getNombre());
            especialidadEncontrado->setDescripcion(especialidad->getDescripcion());
            break;
        }
    }
    return especialidadEncontrado;
}

/****************************************************************************************************************************/
/****************************************************************************************************************************/
/****************************************************************************************************************************/
// Método para listar especialidades desde un archivo binario
List<Especialidad^>^ EspecialidadController::listarEspecialidadesBin(String^ pathArchivo) {
    Stream^ stream = File::Open(pathArchivo, FileMode::Open);
    BinaryFormatter^ formateador = gcnew BinaryFormatter();
    List<Especialidad^>^ listaEspecialidades = dynamic_cast<List<Especialidad^>^>(formateador->Deserialize(stream));
    stream->Close();
    return listaEspecialidades;
}

// Método para escribir especialidades en archivo
void EspecialidadController::escribirArchivoBin(List<Especialidad^>^ listaEspecialidades, String^ pathArchivo) {
    //Creamos el archivo
    Stream^ stream = File::Open(pathArchivo, FileMode::Create);
    BinaryFormatter^ formateador = gcnew BinaryFormatter();
    formateador->Serialize(stream, listaEspecialidades);
    stream->Close();
}

// Método para agregar Especialidad
void EspecialidadController::agregarEspecialidad(int idEspecialidad, String^ nombre, String^ descripcion, String^ pathArchivo) {
    List<Especialidad^>^ listaEspecialidades = listarEspecialidadesBin(pathArchivo);
    // Crear objeto Especialidad
    Especialidad^ especialidad = gcnew Especialidad();
    // Asignar propiedades de Especialidad
    especialidad->setIdEspecialidad(idEspecialidad);
    especialidad->setNombre(nombre);
    especialidad->setDescripcion(descripcion);

    listaEspecialidades->Add(especialidad);
    escribirArchivoBin(listaEspecialidades, pathArchivo);
}

void EspecialidadController::modificarEspecialidad(int idEspecialidad, String^ nombre, String^ descripcion, String^ pathArchivo) {
    List<Especialidad^>^ listaEspecialidades = listarEspecialidadesBin(pathArchivo);
    for (int i = 0; i < listaEspecialidades->Count; i++) {
        Especialidad^ especialidad = listaEspecialidades[i];
        if (especialidad->getIdEspecialidad() == idEspecialidad) {
            // Modificar datos del médico
            especialidad->setIdEspecialidad(idEspecialidad);
            especialidad->setNombre(nombre);
            especialidad->setDescripcion(descripcion);
            break; // Salimos del bucle For
        }
    }
    escribirArchivoBin(listaEspecialidades, pathArchivo);
}

void EspecialidadController::eliminarEspecialidad(int idEspecialidad, String^ pathArchivo) {
    List<Especialidad^>^ listaEspecialidades = listarEspecialidadesBin(pathArchivo);
    for (int i = 0; i < listaEspecialidades->Count; i++) {
        Especialidad^ especialidad = listaEspecialidades[i];
        if (especialidad->getIdEspecialidad() == idEspecialidad) {
            listaEspecialidades->RemoveAt(i);
            break; // Salimos del bucle For
        }
    }
    escribirArchivoBin(listaEspecialidades, pathArchivo);
}

Especialidad^ EspecialidadController::buscarEspecialidadByIdBin(int idEspecialidad, String^ pathArchivo) {
    List<Especialidad^>^ listaEspecialidades = listarEspecialidadesBin(pathArchivo);
    Especialidad^ especialidadEncontrado = gcnew Especialidad();
    for each (Especialidad ^ especialidad in listaEspecialidades) {
        if (especialidad->getIdEspecialidad() == idEspecialidad) {
            // Verificar por ID de especialidad
            especialidadEncontrado->setIdEspecialidad(especialidad->getIdEspecialidad());
            especialidadEncontrado->setNombre(especialidad->getNombre());
            especialidadEncontrado->setDescripcion(especialidad->getDescripcion());
            break;
        }
    }
    return especialidadEncontrado;
}

// Método para buscar especialidades por nombr
List<Especialidad^>^ EspecialidadController::buscarEspecialidadByNombreBin(String^ sNombre, String^ pathArchivo) {
    List<Especialidad^>^ listaEspecialidades = listarEspecialidadesBin(pathArchivo);
    List<Especialidad^>^ listaEncontrados = gcnew List<Especialidad^>();
    for each (Especialidad ^ especialidad in listaEspecialidades) {
        if (especialidad->getNombre()->Contains(sNombre)) {
            // Contiene el nombre
            listaEncontrados->Add(especialidad);
        }
    }
    return listaEncontrados;
}