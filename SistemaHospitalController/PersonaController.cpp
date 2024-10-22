#include "PersonaController.h"

using namespace SistemaHospitalController;

PersonaController::PersonaController() {

}

// Método para listar todas las personas
List<Persona^>^ PersonaController::listarPersonas() {
    List<Persona^>^ listaPersonas = gcnew List<Persona^>();
    //array<String^>^ lineasArchivo = File::ReadAllLines("Personas.txt");
    //String^ separadores = ";";
    //String^ separadorLista = ",";
    //for each (String ^ linea in lineasArchivo) {
    //    /*Voy a separar los datos de una linea en un arreglo de string*/
    //    array<String^>^ datos = linea->Split(separadores->ToCharArray());
    //    //Clase Persona
    //    int idPersona = Convert::ToInt32(datos[0]);
    //    String^ nombres = datos[1];
    //    int fechaNacimiento = Convert::ToInt32(datos[2]);
    //    String^ genero = datos[3];
    //    String^ direccion = datos[4];
    //    String^ telefonos = datos[5];
    //    String^ email = datos[6];
    //    String^ estadoCivil = datos[7];
    //    float altura = Convert::ToSingle(datos[8]);

    //    // Crear objeto Persona y añadir a la lista
    //    Persona^ persona = gcnew Persona();
    //    // Asignar propiedades de Persona
    //    persona->setIdPersona(idPersona);
    //    persona->setNombres(nombres);
    //    persona->setFechaNacimiento(fechaNacimiento);
    //    persona->setGenero(genero);
    //    persona->setDireccion(direccion);
    //    persona->setTelefonos(telefonos);
    //    persona->setEmail(email);
    //    persona->setEstadoCivil(estadoCivil);
    //    persona->setAltura(altura);
    //    
    //    listaPersonas->Add(persona);
    //}
    return listaPersonas;
}

// Método que retorna la información de una persona por IdPersona
Persona^ PersonaController::buscarPersonaById(int idPersona) {
    List<Persona^>^ listaPersonas = listarPersonas();
    Persona^ personaEncontrado = gcnew Persona();
    for each (Persona ^ persona in listaPersonas) {
        if (persona->getIdPersona() == idPersona) {
            // Verificar por ID de médico
            personaEncontrado->setIdPersona(persona->getIdPersona());
            personaEncontrado->setNombres(persona->getNombres());
            personaEncontrado->setFechaNacimiento(persona->getFechaNacimiento());
            personaEncontrado->setGenero(persona->getGenero());
            personaEncontrado->setDireccion(persona->getDireccion());
            personaEncontrado->setTelefonos(persona->getTelefonos());
            personaEncontrado->setEmail(persona->getEmail());
            personaEncontrado->setEstadoCivil(persona->getEstadoCivil());
            personaEncontrado->setAltura(persona->getAltura());
            break;
        }
    }
    return personaEncontrado;
}

// Método que retorna la información de una persona por usuario y contraseña
Persona^ PersonaController::buscarPersonaByUsuario(String^ usuario, String^ contrasenia) {
    Persona^ objPersona;
    String^ sSql = "Select idPersona, apellidos, nombres, fechaNacimiento, genero, direccion, telefonos, email, estadoCivil, altura, tipoDocumento, numeroDocumento, usuario, contrasenia ";
    sSql += "From persona Where usuario = '" + usuario + "' and contrasenia = '" + contrasenia + "' ";
    abrirConexion();
    /*objCommand viene a ser el objeto que utilizare para ejecutar el query o sentencia de la BD*/
    SqlCommand^ objCommand = gcnew SqlCommand();
    /*Aqui voy a indicar la sentencia SQL que voy a ejecutar*/
    objCommand->CommandText = sSql;
    /*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
    objCommand->Connection = this->getObjConexion();
    /*Aqui ejecuto la sentencia en la Base de Datos*/
    /*Para Select siempre sera ExecuteReader*/
    /*Para select siempre va a devolver un SqlDataReader*/
    SqlDataReader^ objData = objCommand->ExecuteReader();
    while (objData->Read()) {
        int idPersona = safe_cast<int>(objData[0]);
        String^ apellidos = safe_cast<String^>(objData[1]);
        String^ nombres = safe_cast<String^>(objData[2]);
        int fechaNacimiento = safe_cast<int>(objData[3]);
        String^ genero = safe_cast<String^>(objData[4]);
        String^ direccion = safe_cast<String^>(objData[5]);
        String^ telefonos = safe_cast<String^>(objData[6]);
        String^ email = safe_cast<String^>(objData[7]);
        String^ estadoCivil = safe_cast<String^>(objData[8]);
        double altura = safe_cast<double>(objData[9]);
        String^ tipoDocumento = safe_cast<String^>(objData[10]); 
        String^ numeroDocumento = safe_cast<String^>(objData[11]); 
        String^ usuario = safe_cast<String^>(objData[12]);
        String^ contrasenia = safe_cast<String^>(objData[13]);
        objPersona = gcnew Persona(idPersona, apellidos, nombres, fechaNacimiento, genero, direccion, telefonos, email, estadoCivil, altura, tipoDocumento, numeroDocumento, usuario, contrasenia);
    }
    cerrarConexion();
    return objPersona;
}

////Operaciones con Base de Datos
//void PersonaController::insertPersona(int idPersona, String^ nombre, int fechaNacimiento, String^ genero, String^ direccion, String^ telefono, String^ email, String^ estadoCivil, float altura, int idPersona, String^ numeroColegioPersona, List<String^>^ certificaciones, List<Especialidad^>^ especialidades, List<int>^ idCitasAsignadas, List<Paciente^>^ pacientesAsociados) {
//    abrirConexion();
//    //Insertamos la persona empleando adicionalmente la consulta SQL con SCOPE_IDENTITY() para obtener el valor de la columna Identity
//    //idPersona, no se remite, por cuanto el valor lo asigna la base de datos
//    String^ sSql = "Insert into persona (nombre, fechaNacimiento, genero, direccion, telefono, email, estadoCivil, altura)";
//    sSql += " values('" + nombre + "', " + fechaNacimiento + ", '" + genero + "', '" + direccion + "', '" + telefono + "', '" + email + "', '" + estadoCivil + "', " + altura + " )";
//    sSql += "; SELECT SCOPE_IDENTITY();"; // Obtiene el valor del idPersona generado
//    SqlCommand^ objCommand = gcnew SqlCommand();
//    objCommand->CommandText = sSql;
//    objCommand->Connection = this->getObjConexion();
//    // Ejecutar el comando y obtener el ID generado
//    int idPersonaGenerado = Convert::ToInt32(objCommand->ExecuteScalar());
//
//    //Insertamos la persona: idPersona no se remite, por cuanto el valor lo asigna la base de datos
//    sSql = "Insert into persona (idPersona, numeroColegioPersona, certificaciones)";
//    sSql += " values(" + idPersonaGenerado + ", '" + numeroColegioPersona + "', '" + certificaciones + "')";
//    sSql += "; SELECT SCOPE_IDENTITY();"; // Obtiene el valor del idPersona generado
//    objCommand->CommandText = sSql;
//    objCommand->Connection = this->getObjConexion();
//    // Ejecutar el comando y obtener el ID generado
//    int idPersonaGenerado = Convert::ToInt32(objCommand->ExecuteScalar());
//
//    //Insertamos persona_especialidad: 
//    for each (Especialidad ^ objEspecialidad in especialidades) {
//        sSql = "Insert into persona_especialidad (idPersona, idEspecialidad)";
//        sSql += " values(" + idPersonaGenerado + ", " + objEspecialidad->getIdEspecialidad() + ")";
//        objCommand->CommandText = sSql;
//        objCommand->Connection = this->getObjConexion();
//        objCommand->ExecuteNonQuery();
//    }
//    cerrarConexion();
//}