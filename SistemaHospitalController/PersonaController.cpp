#include "PersonaController.h"
#include <exception>

using namespace SistemaHospitalController;

PersonaController::PersonaController() {

}

// M�todo para listar todas las personas
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

    //    // Crear objeto Persona y a�adir a la lista
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

// M�todo que retorna la informaci�n de una persona por IdPersona
Persona^ PersonaController::buscarPersonaById(int idPersona) {
    List<Persona^>^ listaPersonas = listarPersonas();
    Persona^ personaEncontrado = gcnew Persona();
    for each (Persona ^ persona in listaPersonas) {
        if (persona->getIdPersona() == idPersona) {
            // Verificar por ID de m�dico
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

/*************************************************************************************************************/
/*************************************************************************************************************/
/*************************************************************************************************************/
//Operaciones con Base de Datos
String^ PersonaController::insertPersona(int idPersona, String^ apellidos, String^ nombres, int fechaNacimiento, String^ genero, String^ direccion, String^ telefonos, String^ email, String^ estadoCivil, float altura, String^ tipoDocumento, String^ numeroDocumento) {
    String^ sMessageBox = "";
    try
    {
        abrirConexion();
        //Insertamos la persona empleando adicionalmente la consulta SQL con SCOPE_IDENTITY() para obtener el valor de la columna Identity
        //idPersona, no se remite, por cuanto el valor lo asigna la base de datos
        String^ sSql = "Insert into persona (apellidos, nombres, fechaNacimiento, genero, direccion, telefonos, email, estadoCivil, altura, tipodocumento, numerodocumento)";
        sSql += " values('" + apellidos + "', '" + nombres + "', " + fechaNacimiento + ", '" + genero + "', '" + direccion + "', '" + telefonos + "', '" + email + "', '" + estadoCivil + "', " + altura + ", '" + tipoDocumento + "', '" + numeroDocumento + "')";
        sSql += "; SELECT SCOPE_IDENTITY();"; // Obtiene el valor del idPersona generado
        SqlCommand^ objCommand = gcnew SqlCommand();
        objCommand->CommandText = sSql;
        objCommand->Connection = this->getObjConexion();
        // Ejecutar el comando y obtener el idPersona que la BD ha asignado
        int idPersona = Convert::ToInt32(objCommand->ExecuteScalar());
        sMessageBox = Convert::ToString(idPersona); //Pasamos un idPersona valido en formato string
    }
    catch (SqlException^ ex)
    {
        // Manejar excepciones relacionadas con SQL Server
        sMessageBox = "Error de base de datos: " + ex->Message;
    }
    catch (InvalidOperationException^ ex)
    {
        // Manejar excepciones relacionadas con operaciones no v�lidas
        sMessageBox = "Error de operaciones no v�lidas: " + ex->Message;
    }
    catch (Exception^ ex)
    {
        // Manejar cualquier otra excepci�n general
        sMessageBox = "Error: " + ex->Message;
    }
    finally {
        cerrarConexion();
    }
    return sMessageBox;
}

String^ PersonaController::updatePersona(int idPersona, String^ apellidos, String^ nombres, int fechaNacimiento, String^ genero, String^ direccion, String^ telefonos, String^ email, String^ estadoCivil, float altura, String^ tipoDocumento, String^ numeroDocumento) {
    String^ sMessageBox = "";
    try
    {
        abrirConexion();
        //Actualizamos los datos de la persona
        //Importante: idPersona, debe formar parte de la clausula WHERE
        String^ sSql = "update persona set ";
        sSql += " apellidos = '" + apellidos + "', ";
        sSql += " nombres = '" + nombres + "', ";
        sSql += " fechaNacimiento = " + fechaNacimiento + ", ";
        sSql += " genero = '" + genero + "', ";
        sSql += " direccion = '" + direccion + "', ";
        sSql += " telefonos = '" + telefonos + "', ";
        sSql += " email = '" + email + "', ";
        sSql += " estadoCivil = '" + estadoCivil + "', ";
        sSql += " altura = " + altura + ", ";
        sSql += " tipodocumento = '" + tipoDocumento + "', ";
        sSql += " numerodocumento = '" + numeroDocumento + "' ";
        sSql += " where idPersona =  " + idPersona + " ";
        SqlCommand^ objCommand = gcnew SqlCommand();
        objCommand->CommandText = sSql;
        objCommand->Connection = this->getObjConexion();
        // Ejecutar la sentencia
        objCommand->ExecuteNonQuery();
    }
    catch (SqlException^ ex)
    {
        // Manejar excepciones relacionadas con SQL Server
        sMessageBox = "Error de base de datos: " + ex->Message;
    }
    catch (InvalidOperationException^ ex)
    {
        // Manejar excepciones relacionadas con operaciones no v�lidas
        sMessageBox = "Error de operaci�n no valida: " + ex->Message;
    }
    catch (Exception^ ex)
    {
        // Manejar cualquier otra excepci�n general
        sMessageBox = "Error: " + ex->Message;
    }
    finally {
        cerrarConexion();
    }
    return sMessageBox;
}

String^ PersonaController::deletePersona(int idPersona) {
    String^ sMessageBox = "";
    try
    {
        abrirConexion();
        //Eliminamos el registro de la persona
        //Importante: idPersona, debe formar parte de la clausula WHERE
        String^ sSql = "delete from persona where idPersona =  " + idPersona + " ";
        SqlCommand^ objCommand = gcnew SqlCommand();
        objCommand->CommandText = sSql;
        objCommand->Connection = this->getObjConexion();
        // Ejecutar la sentencia
        objCommand->ExecuteNonQuery();
    }
    catch (SqlException^ ex)
    {
        // Manejar excepciones relacionadas con SQL Server
        sMessageBox = "Error de base de datos: " + ex->Message;
    }
    catch (InvalidOperationException^ ex)
    {
        // Manejar excepciones relacionadas con operaciones no v�lidas
        sMessageBox = "Error de operaci�n no valida: " + ex->Message;
    }
    catch (Exception^ ex)
    {
        // Manejar cualquier otra excepci�n general
        sMessageBox = "Error: " + ex->Message;
    }
    finally {
        cerrarConexion();
    }
    return sMessageBox;
}

// M�todo que retorna la informaci�n de una persona por usuario y contrase�a
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
    if (objData->Read()) {
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
