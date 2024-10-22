#include "EspecialidadController.h"

using namespace SistemaHospitalController;
using namespace System::IO; //Para leer archivos

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