#include "PacienteController.h"

using namespace SistemaHospitalController;
using namespace System::IO; //Para leer archivos

PacienteController::PacienteController() {

}

// Método para listar Pacientes
List<Paciente^>^ PacienteController::listarPacientes() {
    List<Paciente^>^ listaPacientes = gcnew List<Paciente^>();
    array<String^>^ lineasArchivo = File::ReadAllLines("Pacientes.txt");
    String^ separadores = ";";
    String^ separadorLista = ",";
    for each (String ^ linea in lineasArchivo) {
        /*Voy a separar los datos de una linea en un arreglo de string*/
        array<String^>^ datos = linea->Split(separadores->ToCharArray());
        //Clase Persona
        int idPersona = Convert::ToInt32(datos[0]);
        String^ nombres = datos[1];
        int fechaNacimiento = Convert::ToInt32(datos[2]);
        String^ genero = datos[3];
        String^ direccion = datos[4];
        String^ telefonos = datos[5];
        String^ email = datos[6];
        String^ estadoCivil = datos[7];
        float altura = Convert::ToSingle(datos[8]);
        //Clase Paciente
        int idPaciente = Convert::ToInt32(datos[9]);
        String^ numeroSeguroSocial = datos[10];
        String^ grupoSanguíneo = datos[11];
        List<String^>^ alergias = gcnew List<String^>();
        alergias->Add(datos[12]);
        String^ contactoEmergencia = datos[13];
        List<String^>^ diagnosticos = gcnew List<String^>();
        diagnosticos->Add(datos[14]);
               
        // Crear objeto Paciente y añadir a la lista
        Paciente^ objPaciente = gcnew Paciente();
        // Asignar propiedades de Persona
        objPaciente->setIdPersona(idPersona);
        objPaciente->setNombres(nombres);
        objPaciente->setFechaNacimiento(fechaNacimiento);
        objPaciente->setGenero(genero);
        objPaciente->setDireccion(direccion);
        objPaciente->setTelefonos(telefonos);
        objPaciente->setEmail(email);
        objPaciente->setEstadoCivil(estadoCivil);
        objPaciente->setAltura(altura);
        // Asignar propiedades de Paciente
        objPaciente->setIdPaciente(idPaciente);
        objPaciente->setNumeroSeguroSocial(numeroSeguroSocial);
        objPaciente->setGrupoSanguíneo(grupoSanguíneo);
        objPaciente->setAlergias(alergias);
        objPaciente->setContactoEmergencia(contactoEmergencia);
        objPaciente->setDiagnosticos(diagnosticos);

        listaPacientes->Add(objPaciente);
    }
    return listaPacientes;
}

// Método para buscar pacientes por IdPaciente
Paciente^ PacienteController::buscarPacienteById(int idPaciente) {
    List<Paciente^>^ listaPacientes = listarPacientes();
    Paciente^ pacienteEncontrado = gcnew Paciente();
    for each (Paciente ^ paciente in listaPacientes) {
        if (paciente->getIdPaciente() == idPaciente) {
            // Verificar por ID de médico
            pacienteEncontrado->setIdPersona(paciente->getIdPersona());
            pacienteEncontrado->setNombres(paciente->getNombres());
            pacienteEncontrado->setFechaNacimiento(paciente->getFechaNacimiento());
            pacienteEncontrado->setGenero(paciente->getGenero());
            pacienteEncontrado->setDireccion(paciente->getDireccion());
            pacienteEncontrado->setTelefonos(paciente->getTelefonos());
            pacienteEncontrado->setEmail(paciente->getEmail());
            pacienteEncontrado->setEstadoCivil(paciente->getEstadoCivil());
            pacienteEncontrado->setAltura(paciente->getAltura());
            pacienteEncontrado->setIdPaciente(paciente->getIdPaciente());
            pacienteEncontrado->setNumeroSeguroSocial(paciente->getNumeroSeguroSocial());
            pacienteEncontrado->setGrupoSanguíneo(paciente->getGrupoSanguíneo());
            pacienteEncontrado->setAlergias(paciente->getAlergias());
            pacienteEncontrado->setContactoEmergencia(paciente->getContactoEmergencia());
            pacienteEncontrado->setDiagnosticos(paciente->getDiagnosticos());
            break;
        }
    }
    return pacienteEncontrado;
}

/****************************************************************************************************************************/
/****************************************************************************************************************************/
/****************************************************************************************************************************/
//Operaciones con Base de Datos
List<Paciente^>^ PacienteController::selectPacientes() {
    List<Paciente^>^ listaPacientes = gcnew List<Paciente^>();
    String^ separadores = ";";
    String^ separadorLista = ",";

    String^ sSql = "Select idPaciente, apellidos, nombres, fechaNacimiento, genero, direccion, telefonos, email, estadoCivil, altura, tipoDocumento, numeroDocumento ";
    sSql += "From paciente ";
    sSql += "Order by apellidos, nombres ";
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
        //Paciente
        int idPaciente = safe_cast<int>(objData[0]);
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
        Paciente^ objPaciente = gcnew Paciente();
        // Asignar propiedades de Persona
        objPaciente->setIdPaciente(idPaciente);
        objPaciente->setApellidos(apellidos);
        objPaciente->setNombres(nombres);
        objPaciente->setFechaNacimiento(fechaNacimiento);
        objPaciente->setGenero(genero);
        objPaciente->setDireccion(direccion);
        objPaciente->setTelefonos(telefonos);
        objPaciente->setEmail(email);
        objPaciente->setEstadoCivil(estadoCivil);
        objPaciente->setAltura(altura);
        objPaciente->setTipoDocumento(tipoDocumento);
        objPaciente->setNumeroDocumento(numeroDocumento);
        listaPacientes->Add(objPaciente);
    }
    cerrarConexion();

    return listaPacientes;
}

// Método que retorna la información de un medico por IdPaciente
Paciente^ PacienteController::getPacienteById(int idPaciente) {
    Paciente^ objPaciente;
    String^ separadores = ";";
    String^ separadorLista = ",";

    String^ sSql = "Select p.idPersona, p.apellidos, p.nombres, p.fechaNacimiento, p.genero, p.direccion, p.telefonos, p.email, p.estadoCivil, p.altura, p.tipoDocumento, p.numeroDocumento, ";
    sSql += "m.idPaciente, m.numeroColegioPaciente, m.certificaciones ";
    sSql += "From persona p, medico m ";
    sSql += "Where p.idPersona = m.idPersona and m.idPaciente = " + idPaciente;
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
    //if (objData->Read()) {
    //    //Persona
    //    int idPersona = safe_cast<int>(objData[0]);
    //    String^ apellidos = safe_cast<String^>(objData[1]);
    //    String^ nombres = safe_cast<String^>(objData[2]);
    //    int fechaNacimiento = safe_cast<int>(objData[3]);
    //    String^ genero = safe_cast<String^>(objData[4]);
    //    String^ direccion = safe_cast<String^>(objData[5]);
    //    String^ telefonos = safe_cast<String^>(objData[6]);
    //    String^ email = safe_cast<String^>(objData[7]);
    //    String^ estadoCivil = safe_cast<String^>(objData[8]);
    //    double altura = safe_cast<double>(objData[9]);
    //    String^ tipoDocumento = safe_cast<String^>(objData[10]);
    //    String^ numeroDocumento = safe_cast<String^>(objData[11]);
    //    //Paciente
    //    int idPaciente = safe_cast<int>(objData[12]);
    //    String^ numeroColegioPaciente = safe_cast<String^>(objData[13]);

    //    //Lista de Certificados
    //    array<String^>^ listaCertificados = safe_cast<String^>(objData[14])->Split(separadorLista->ToCharArray());
    //    List<String^>^ certificaciones = gcnew List<String^>();
    //    for each (String ^ certificado in listaCertificados) {
    //        certificaciones->Add(certificado);
    //    }

    //    List<Especialidad^>^ especialidades = gcnew List<Especialidad^>();
    //    List<int>^ idCitasAsignadas = gcnew List<int>();
    //    List<Paciente^>^ pacientesAsociados = gcnew List<Paciente^>();
    //    //idPersona, apellidos, nombres, fechaNacimiento, genero, direccion, telefonos, email, estadoCivil, altura, , 
    //    objPaciente = gcnew Paciente(idPaciente, numeroColegioPaciente, certificaciones, especialidades, idCitasAsignadas, pacientesAsociados);
    //    // Asignar propiedades de Persona
    //    objPaciente->setIdPersona(idPersona);
    //    objPaciente->setApellidos(apellidos);
    //    objPaciente->setNombres(nombres);
    //    objPaciente->setFechaNacimiento(fechaNacimiento);
    //    objPaciente->setGenero(genero);
    //    objPaciente->setDireccion(direccion);
    //    objPaciente->setTelefonos(telefonos);
    //    objPaciente->setEmail(email);
    //    objPaciente->setEstadoCivil(estadoCivil);
    //    objPaciente->setAltura(altura);
    //    objPaciente->setTipoDocumento(tipoDocumento);
    //    objPaciente->setNumeroDocumento(numeroDocumento);
    //}
    //// Cerrar el DataReader después de usarlo
    //objData->Close();
    //List<Especialidad^>^ especialidades = gcnew List<Especialidad^>();
    //sSql = "Select idEspecialidad From medico_especialidad Where idPaciente = " + idPaciente;
    //objCommand->CommandText = sSql;
    //objData = objCommand->ExecuteReader();
    //while (objData->Read()) {
    //    //Persona
    //    int idEspecialidad = safe_cast<int>(objData[0]);
    //    EspecialidadController^ objController = gcnew EspecialidadController();
    //    Especialidad^ especialidad = objController->buscarEspecialidadById(idEspecialidad);
    //    especialidades->Add(especialidad);
    //}
    //if (especialidades->Count > 0)
    //{
    //    objPaciente->setEspecialidades(especialidades);
    //}
    cerrarConexion();
    return objPaciente;
}

String^ PacienteController::insertPaciente(int idPaciente, String^ apellidos, String^ nombres, int fechaNacimiento, String^ genero, String^ direccion, String^ telefonos, String^ email, String^ estadoCivil, float altura, String^ tipoDocumento, String^ numeroDocumento) {
    String^ sMessageBox = "";
    try
    {
        //PersonaController^ objControler = gcnew PersonaController();
        //sMessageBox = objControler->insertPersona(idPersona, apellidos, nombres, fechaNacimiento, genero, direccion, telefonos, email, estadoCivil, altura, tipoDocumento, numeroDocumento);
        //if (Convert::ToInt32(sMessageBox) > 0)
        //{   //Si sMessageBox es un valor valido
        //    idPersona = Convert::ToInt32(sMessageBox);
        //    abrirConexion();
        //    // Serializar certificaciones
        //    String^ listCertificados;
        //    if (certificaciones->Count > 0) {
        //        listCertificados = String::Join(",", certificaciones);
        //    }
        //    //Insertamos la medico: idPaciente no se remite, por cuanto el valor lo asigna la base de datos
        //    String^ sSql = "Insert into medico (idPersona, numeroColegioPaciente, certificaciones)";
        //    sSql += " values(" + idPersona + ", '" + numeroColegioPaciente + "', '" + listCertificados + "')";
        //    sSql += "; SELECT SCOPE_IDENTITY();"; // Obtiene el valor del idPaciente generado
        //    SqlCommand^ objCommand = gcnew SqlCommand();
        //    objCommand->CommandText = sSql;
        //    objCommand->Connection = this->getObjConexion();
        //    // Ejecutar el comando y obtener el idPaciente obtenido por la BD
        //    int idPacienteGenerado = Convert::ToInt32(objCommand->ExecuteScalar());
        //    //Insertamos medico_especialidad: 
        //    for each (Especialidad ^ objEspecialidad in especialidades) {
        //        sSql = "Insert into medico_especialidad (idPaciente, idEspecialidad)";
        //        sSql += " values(" + idPacienteGenerado + ", " + objEspecialidad->getIdEspecialidad() + ")";
        //        objCommand->CommandText = sSql;
        //        objCommand->Connection = this->getObjConexion();
        //        objCommand->ExecuteNonQuery();
        //    }
        //}
    }
    catch (SqlException^ ex)
    {
        // Manejar excepciones relacionadas con SQL Server
        sMessageBox = "Error de base de datos: " + ex->Message;
    }
    catch (InvalidOperationException^ ex)
    {
        // Manejar excepciones relacionadas con operaciones no válidas
        sMessageBox = "Error de operaciones no válidas: " + ex->Message;
    }
    catch (Exception^ ex)
    {
        // Manejar cualquier otra excepción general
        sMessageBox = "Error de base de datos: " + ex->Message;
    }
    finally {
        cerrarConexion();
    }
    return sMessageBox;
}

String^ PacienteController::updatePaciente(int idPaciente, String^ apellidos, String^ nombres, int fechaNacimiento, String^ genero, String^ direccion, String^ telefonos, String^ email, String^ estadoCivil, float altura, String^ tipoDocumento, String^ numeroDocumento) {
    String^ sMessageBox = "";
    //try
    //{
    //    PersonaController^ objControler = gcnew PersonaController();
    //    sMessageBox = objControler->updatePersona(idPersona, apellidos, nombres, fechaNacimiento, genero, direccion, telefonos, email, estadoCivil, altura, tipoDocumento, numeroDocumento);
    //    if (sMessageBox->Equals(""))
    //    {
    //        abrirConexion();
    //        // Serializar certificaciones
    //        String^ listCertificados;
    //        if (certificaciones->Count > 0) {
    //            listCertificados = String::Join(",", certificaciones);
    //        }
    //        //Insertamos la medico: idPaciente no se remite, por cuanto el valor lo asigna la base de datos
    //        String^ sSql = "Update medico Set ";
    //        sSql += " idPersona = " + idPersona + ", ";
    //        sSql += " numeroColegioPaciente = '" + numeroColegioPaciente + "', ";
    //        sSql += " certificaciones = '" + listCertificados + "' ";
    //        sSql += " Where idPaciente = " + idPaciente + " ";
    //        SqlCommand^ objCommand = gcnew SqlCommand();
    //        objCommand->CommandText = sSql;
    //        objCommand->Connection = this->getObjConexion();
    //        // Ejecutar la sentencia
    //        objCommand->ExecuteNonQuery();

    //        //Eliminamos todos los registros relacionados a idPaciente en la tabla medico_especialidad
    //        sSql = "Delete From medico_especialidad Where idPaciente = " + idPaciente + " ";
    //        objCommand->CommandText = sSql;
    //        objCommand->Connection = this->getObjConexion();
    //        objCommand->ExecuteNonQuery();
    //        //Volvemos a insertar todos las especialidades del idPaciente en medico_especialidad: 
    //        for each (Especialidad ^ objEspecialidad in especialidades) {
    //            sSql = "Insert into medico_especialidad (idPaciente, idEspecialidad)";
    //            sSql += " values(" + idPaciente + ", " + objEspecialidad->getIdEspecialidad() + ")";
    //            objCommand->CommandText = sSql;
    //            objCommand->Connection = this->getObjConexion();
    //            objCommand->ExecuteNonQuery();
    //        }
    //    }

    //}
    //catch (SqlException^ ex)
    //{
    //    // Manejar excepciones relacionadas con SQL Server
    //    sMessageBox = "Error de base de datos: " + ex->Message;
    //}
    //catch (InvalidOperationException^ ex)
    //{
    //    // Manejar excepciones relacionadas con operaciones no válidas
    //    sMessageBox = "Error de operaciones no válidas: " + ex->Message;
    //}
    //catch (Exception^ ex)
    //{
    //    // Manejar cualquier otra excepción general
    //    sMessageBox = "Error: " + ex->Message;
    //}
    //finally {
    //    cerrarConexion();
    //}
    return sMessageBox;
}

String^ PacienteController::deletePaciente(int idPaciente) {
    String^ sMessageBox = "";
    try
    {
        Paciente^ objPaciente = getPacienteById(idPaciente);

        abrirConexion();
        SqlCommand^ objCommand = gcnew SqlCommand();

        //Tablas dependientes
        //Eliminamos todos los registros relacionados a idPaciente en la tabla medico_especialidad
        String^ sSql = "Delete From medico_especialidad Where idPaciente = " + idPaciente + " ";
        objCommand->CommandText = sSql;
        objCommand->Connection = this->getObjConexion();
        objCommand->ExecuteNonQuery();

        //Registro
        //Eliminamos el registro relacionado a idPaciente en la tabla medico
        sSql = "Delete From medico Where idPaciente = " + idPaciente + " ";
        objCommand->CommandText = sSql;
        objCommand->Connection = this->getObjConexion();
        objCommand->ExecuteNonQuery();

        cerrarConexion();

        //Analizar si tambien hay que eliminar al Padre, por tratrse de una herencia
        //Eliminamos el registro relacionado a idPaciente en la tabla Persona
        //PersonaController^ objController = gcnew PersonaController();
        //sMessageBox = objController->deletePersona(objPaciente->getIdPersona());
    }
    catch (SqlException^ ex)
    {
        // Manejar excepciones relacionadas con SQL Server
        sMessageBox = "Error de base de datos: " + ex->Message;
    }
    catch (InvalidOperationException^ ex)
    {
        // Manejar excepciones relacionadas con operaciones no válidas
        sMessageBox = "Error de operaciones no válidas: " + ex->Message;
    }
    catch (Exception^ ex)
    {
        // Manejar cualquier otra excepción general
        sMessageBox = "Error: " + ex->Message;
    }
    return sMessageBox;
}

List<Paciente^>^ PacienteController::selectPacientesByApellido(String^ apellido) {
    List<Paciente^>^ listaPacientes = selectPacientes();
    List<Paciente^>^ pacientesEncontrados = gcnew List<Paciente^>();
    for each (Paciente ^ paciente in listaPacientes) {
        if (paciente->getApellidos()->Contains(apellido)) {
            // Verificar por ID de médico
            pacientesEncontrados->Add(paciente);
        }
    }
    return pacientesEncontrados;
}