#include "MedicoController.h"
#include "EspecialidadController.h"
#include "PersonaController.h"

using namespace SistemaHospitalController;
using namespace System::IO; //Para leer archivos

MedicoController::MedicoController() {

}

// Método para listar médicos
List<Medico^>^ MedicoController::listarMedicos() {
    List<Medico^>^ listaMedicos = gcnew List<Medico^>();
    array<String^>^ lineasArchivo = File::ReadAllLines("Medicos.txt");
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
        //Clase Médico
        int idMedico = Convert::ToInt32(datos[9]);
        String^ numeroColegioMedico = datos[10];
        
        //Lista de Certificados
        List<String^>^ certificaciones = gcnew List<String^>();
        array<String^>^ listaCertificados = datos[11]->Split(separadorLista->ToCharArray());
        for each (String ^ certificado in listaCertificados) {
            certificaciones->Add(certificado);
        }
        
        List<Especialidad^>^ especialidades = gcnew List<Especialidad^>();
        array<String^>^ listaIds = datos[12]->Split(separadorLista->ToCharArray());
        for each (String ^ id in listaIds) {
            if (!id->Equals(""))
            {
                EspecialidadController^ objEspecialidad = gcnew EspecialidadController();
                especialidades->Add(objEspecialidad->buscarEspecialidadById(Convert::ToInt32(id)));
            }
        }

        List<int>^ idCitasAsignadas = gcnew List<int>();
        List<Paciente^>^ pacientesAsociados = gcnew List<Paciente^>();
        
        // Crear objeto Medico y añadir a la lista
        Medico^ medico = gcnew Medico();
        // Asignar propiedades de Persona
        medico->setIdPersona(idPersona);
        medico->setNombres(nombres);
        medico->setFechaNacimiento(fechaNacimiento);
        medico->setGenero(genero);
        medico->setDireccion(direccion);
        medico->setTelefonos(telefonos);
        medico->setEmail(email);
        medico->setEstadoCivil(estadoCivil);
        medico->setAltura(altura);
        // Asignar propiedades de Medico
        medico->setIdMedico(idMedico);
        medico->setNumeroColegioMedico(numeroColegioMedico);
        medico->setCertificaciones(certificaciones);
        medico->setEspecialidades(especialidades);
        medico->setidCitasAsignadas(idCitasAsignadas);
        medico->setPacientesAsociados(pacientesAsociados);

        listaMedicos->Add(medico);
    }
    return listaMedicos;
}

// Método para agregar médico
void MedicoController::agregarMedico(int idPersona, String^ apellidos, String^ nombres, int fechaNacimiento, String^ genero, String^ direccion, String^ telefonos, String^ email, String^ estadoCivil, float altura, String^ tipoDocumento, String^ numeroDocumento, int idMedico, String^ numeroColegioMedico, List<String^>^ certificaciones, List<Especialidad^>^ especialidades, List<int>^ idCitasAsignadas, List<Paciente^>^ pacientesAsociados) {
    List<Medico^>^ listaMedicos = listarMedicos();
    // Crear objeto Medico
    Medico^ medico = gcnew Medico();
    // Asignar propiedades de Persona
    medico->setIdPersona(idPersona);
    medico->setApellidos(apellidos);
    medico->setNombres(nombres);
    medico->setFechaNacimiento(fechaNacimiento);
    medico->setGenero(genero);
    medico->setDireccion(direccion);
    medico->setTelefonos(telefonos);
    medico->setEmail(email);
    medico->setEstadoCivil(estadoCivil);
    medico->setAltura(altura);
    medico->setTipoDocumento(tipoDocumento);
    medico->setNumeroDocumento(numeroDocumento);
    // Asignar propiedades de Medico
    medico->setIdMedico(idMedico);
    medico->setNumeroColegioMedico(numeroColegioMedico);
    medico->setCertificaciones(certificaciones);
    medico->setEspecialidades(especialidades);
    medico->setidCitasAsignadas(idCitasAsignadas);
    medico->setPacientesAsociados(pacientesAsociados);

    listaMedicos->Add(medico);
    escribirArchivo(listaMedicos);
}

// Método para escribir médicos en archivo
void MedicoController::escribirArchivo(List<Medico^>^ listaMedicos) {
    array<String^>^ lineasArchivo = gcnew array<String^>(listaMedicos->Count);
    for (int i = 0; i < listaMedicos->Count; i++) {
        Medico^ medico = listaMedicos[i];

        // Serializar certificaciones
        String^ certificaciones = String::Join(",", medico->getCertificaciones()->ToArray());

        // Serializar sólo los IDs de especialidad
        List<String^>^ idsEspecialidades = gcnew List<String^>();
        for each (Especialidad ^ especialidad in medico->getEspecialidades()) {
            idsEspecialidades->Add(especialidad->getIdEspecialidad().ToString());
        }
        String^ especialidades = String::Join(",", idsEspecialidades->ToArray());

        // Serializar idCitasAsignadas
        String^ idCitas = ""; //String::Join(",", medico->getidCitasAsignadas()->ToArray());

        // Serializar pacientes asociados
        String^ pacientesAsociados = ""; //String::Join(",", medico->getPacientesAsociados()->ToArray());


        lineasArchivo[i] = medico->getIdPersona() + ";" +
            medico->getNombres() + ";" +
            medico->getFechaNacimiento() + ";" +
            medico->getGenero() + ";" +
            medico->getDireccion() + ";" +
            medico->getTelefonos() + ";" +
            medico->getEmail() + ";" +
            medico->getEstadoCivil() + ";" +
            medico->getAltura() + ";" +
            medico->getIdMedico() + ";" +
            medico->getNumeroColegioMedico() + ";" +
            certificaciones + ";" +
            especialidades + ";" +
            idCitas + ";" +
            pacientesAsociados;
    }
    File::WriteAllLines("Medicos.txt", lineasArchivo);
}

// Método para modificar médico
void MedicoController::modificarMedico(int idPersona, String^ apellidos, String^ nombres, int fechaNacimiento, String^ genero, String^ direccion, String^ telefonos, String^ email, String^ estadoCivil, float altura, String^ tipoDocumento, String^ numeroDocumento, int idMedico, String^ numeroColegioMedico, List<String^>^ certificaciones, List<Especialidad^>^ especialidades, List<int>^ idCitasAsignadas, List<Paciente^>^ pacientesAsociados) {
    List<Medico^>^ listaMedicos = listarMedicos();
    for (int i = 0; i < listaMedicos->Count; i++) {
        Medico^ medico = listaMedicos[i];
        if (medico->getIdMedico() == idMedico) {
            // Modificar datos del médico
            medico->setIdPersona(idPersona);
            medico->setNombres(nombres);
            medico->setFechaNacimiento(fechaNacimiento);
            medico->setGenero(genero);
            medico->setDireccion(direccion);
            medico->setTelefonos(telefonos);
            medico->setEmail(email);
            medico->setEstadoCivil(estadoCivil);
            medico->setAltura(altura);
            medico->setNumeroColegioMedico(numeroColegioMedico);
            medico->setCertificaciones(certificaciones);
            medico->setEspecialidades(especialidades);
            medico->setidCitasAsignadas(idCitasAsignadas);
            medico->setPacientesAsociados(pacientesAsociados);
            break; // Salimos del bucle For
        }
    }
    escribirArchivo(listaMedicos); // Escribimos los datos actualizados en el archivo
}

// Método para eliminar médico
void MedicoController::eliminarMedico(int idMedico) {
    List<Medico^>^ listaMedicos = listarMedicos();
    for (int i = 0; i < listaMedicos->Count; i++) {
        Medico^ medico = listaMedicos[i];
        if (medico->getIdMedico() == idMedico) {
            listaMedicos->RemoveAt(i);
            break; // Salimos del bucle For
        }
    }
    escribirArchivo(listaMedicos);
}

// Método para buscar médicos por código o especialidad
List<Medico^>^ MedicoController::buscarMedicosByIdOrEspecialidad(int idMedico, String^ especialidad) {
    List<Medico^>^ listaMedicos = listarMedicos();
    List<Medico^>^ medicosEncontrados = gcnew List<Medico^>();
    for each (Medico ^ medico in listaMedicos) {
        if (medico->getIdMedico() == idMedico) {
            // Verificar por ID de médico
            medicosEncontrados->Add(medico);
        }
        else {
            // Verificar por especialidad
            for each (Especialidad ^ esp in medico->getEspecialidades()) {
                if (esp->getNombre()->Equals(especialidad, StringComparison::InvariantCultureIgnoreCase)) {
                    medicosEncontrados->Add(medico);
                }
            }
        }
    }
    return medicosEncontrados;
}

// Método para buscar médicos por código o especialidad
Medico^ MedicoController::buscarMedicoById(int idMedico) {
    List<Medico^>^ listaMedicos = listarMedicos();
    Medico^ medicoEncontrado = gcnew Medico();
    for each (Medico ^ medico in listaMedicos) {
        if (medico->getIdMedico() == idMedico) {
            // Verificar por ID de médico
            medicoEncontrado->setIdPersona(medico->getIdPersona());
            medicoEncontrado->setNombres(medico->getNombres());
            medicoEncontrado->setFechaNacimiento(medico->getFechaNacimiento());
            medicoEncontrado->setGenero(medico->getGenero());
            medicoEncontrado->setDireccion(medico->getDireccion());
            medicoEncontrado->setTelefonos(medico->getTelefonos());
            medicoEncontrado->setEmail(medico->getEmail());
            medicoEncontrado->setEstadoCivil(medico->getEstadoCivil());
            medicoEncontrado->setAltura(medico->getAltura());
            medicoEncontrado->setIdMedico(medico->getIdMedico());
            medicoEncontrado->setNumeroColegioMedico(medico->getNumeroColegioMedico());
            medicoEncontrado->setCertificaciones(medico->getCertificaciones());
            medicoEncontrado->setEspecialidades(medico->getEspecialidades());
            medicoEncontrado->setidCitasAsignadas(medico->getidCitasAsignadas());
            medicoEncontrado->setPacientesAsociados(medico->getPacientesAsociados());
            break;
        }
    }
    return medicoEncontrado;
}

/****************************************************************************************************************************/
/****************************************************************************************************************************/
/****************************************************************************************************************************/
//Operaciones con Base de Datos
List<Medico^>^ MedicoController::selectMedicos() {
    List<Medico^>^ listaMedicos = gcnew List<Medico^>();
    String^ separadores = ";";
    String^ separadorLista = ",";

    String^ sSql = "Select p.idPersona, p.apellidos, p.nombres, p.fechaNacimiento, p.genero, p.direccion, p.telefonos, p.email, p.estadoCivil, p.altura, p.tipoDocumento, p.numeroDocumento, ";
    sSql += "m.idMedico, m.numeroColegioMedico, m.certificaciones ";
    sSql += "From persona p, medico m ";
    sSql += "Where p.idPersona = m.idPersona ";
    sSql += "Order by p.apellidos, p.nombres ";
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
        //Persona
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
        //Medico
        int idMedico = safe_cast<int>(objData[12]);
        String^ numeroColegioMedico = safe_cast<String^>(objData[13]);

        //Lista de Certificados
        array<String^>^ listaCertificados = safe_cast<String^>(objData[14])->Split(separadorLista->ToCharArray());
        List<String^>^ certificaciones = gcnew List<String^>();
        for each (String ^ certificado in listaCertificados) {
            certificaciones->Add(certificado);
        }

        List<Especialidad^>^ especialidades = gcnew List<Especialidad^>();
        List<int>^ idCitasAsignadas = gcnew List<int>();
        List<Paciente^>^ pacientesAsociados = gcnew List<Paciente^>();
        //idPersona, apellidos, nombres, fechaNacimiento, genero, direccion, telefonos, email, estadoCivil, altura, , 
        Medico^ objMedico = gcnew Medico(idMedico, numeroColegioMedico, certificaciones, especialidades, idCitasAsignadas, pacientesAsociados);
        // Asignar propiedades de Persona
        objMedico->setIdPersona(idPersona);
        objMedico->setApellidos(apellidos);
        objMedico->setNombres(nombres);
        objMedico->setFechaNacimiento(fechaNacimiento);
        objMedico->setGenero(genero);
        objMedico->setDireccion(direccion);
        objMedico->setTelefonos(telefonos);
        objMedico->setEmail(email);
        objMedico->setEstadoCivil(estadoCivil);
        objMedico->setAltura(altura);
        objMedico->setTipoDocumento(tipoDocumento);
        objMedico->setNumeroDocumento(numeroDocumento);
        listaMedicos->Add(objMedico);
    }
    cerrarConexion();

    return listaMedicos;
}

// Método que retorna la información de un medico por IdMedico
Medico^ MedicoController::getMedicoById(int idMedico) {
    Medico^ objMedico;
    String^ separadores = ";";
    String^ separadorLista = ",";

    String^ sSql = "Select p.idPersona, p.apellidos, p.nombres, p.fechaNacimiento, p.genero, p.direccion, p.telefonos, p.email, p.estadoCivil, p.altura, p.tipoDocumento, p.numeroDocumento, ";
    sSql += "m.idMedico, m.numeroColegioMedico, m.certificaciones ";
    sSql += "From persona p, medico m ";
    sSql += "Where p.idPersona = m.idPersona and m.idMedico = " + idMedico;
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
        //Persona
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
        //Medico
        int idMedico = safe_cast<int>(objData[12]);
        String^ numeroColegioMedico = safe_cast<String^>(objData[13]);

        //Lista de Certificados
        array<String^>^ listaCertificados = safe_cast<String^>(objData[14])->Split(separadorLista->ToCharArray());
        List<String^>^ certificaciones = gcnew List<String^>();
        for each (String ^ certificado in listaCertificados) {
            certificaciones->Add(certificado);
        }

        List<Especialidad^>^ especialidades = gcnew List<Especialidad^>();
        List<int>^ idCitasAsignadas = gcnew List<int>();
        List<Paciente^>^ pacientesAsociados = gcnew List<Paciente^>();
        //idPersona, apellidos, nombres, fechaNacimiento, genero, direccion, telefonos, email, estadoCivil, altura, , 
        objMedico = gcnew Medico(idMedico, numeroColegioMedico, certificaciones, especialidades, idCitasAsignadas, pacientesAsociados);
        // Asignar propiedades de Persona
        objMedico->setIdPersona(idPersona);
        objMedico->setApellidos(apellidos);
        objMedico->setNombres(nombres);
        objMedico->setFechaNacimiento(fechaNacimiento);
        objMedico->setGenero(genero);
        objMedico->setDireccion(direccion);
        objMedico->setTelefonos(telefonos);
        objMedico->setEmail(email);
        objMedico->setEstadoCivil(estadoCivil);
        objMedico->setAltura(altura);
        objMedico->setTipoDocumento(tipoDocumento);
        objMedico->setNumeroDocumento(numeroDocumento);
    }
    // Cerrar el DataReader después de usarlo
    objData->Close();
    List<Especialidad^>^ especialidades = gcnew List<Especialidad^>();
    sSql = "Select idEspecialidad From medico_especialidad Where idMedico = " + idMedico;
    objCommand->CommandText = sSql;
    objData = objCommand->ExecuteReader();
    while (objData->Read()) {
        //Persona
        int idEspecialidad = safe_cast<int>(objData[0]);
        EspecialidadController^ objController = gcnew EspecialidadController();
        Especialidad^ especialidad = objController->buscarEspecialidadById(idEspecialidad);
        especialidades->Add(especialidad);
    }
    if (especialidades->Count > 0)
    {
        objMedico->setEspecialidades(especialidades);
    }
    cerrarConexion();
    return objMedico;
}

String^ MedicoController::insertMedico(int idPersona, String^ apellidos, String^ nombres, int fechaNacimiento, String^ genero, String^ direccion, String^ telefonos, String^ email, String^ estadoCivil, float altura, String^ tipoDocumento, String^ numeroDocumento, int idMedico, String^ numeroColegioMedico, List<String^>^ certificaciones, List<Especialidad^>^ especialidades, List<int>^ idCitasAsignadas, List<Paciente^>^ pacientesAsociados) {
    String^ sMessageBox = "";
    try
    {
        PersonaController^ objControler = gcnew PersonaController();
        sMessageBox = objControler->insertPersona(idPersona, apellidos, nombres, fechaNacimiento, genero, direccion, telefonos, email, estadoCivil, altura, tipoDocumento, numeroDocumento);
        if (Convert::ToInt32(sMessageBox) > 0)
        {   //Si sMessageBox es un valor valido
            idPersona = Convert::ToInt32(sMessageBox);
            abrirConexion();
            // Serializar certificaciones
            String^ listCertificados;
            if (certificaciones->Count > 0) {
                listCertificados = String::Join(",", certificaciones);
            } 
            //Insertamos la medico: idMedico no se remite, por cuanto el valor lo asigna la base de datos
            String^ sSql = "Insert into medico (idPersona, numeroColegioMedico, certificaciones)";
            sSql += " values(" + idPersona + ", '" + numeroColegioMedico + "', '" + listCertificados + "')";
            sSql += "; SELECT SCOPE_IDENTITY();"; // Obtiene el valor del idMedico generado
            SqlCommand^ objCommand = gcnew SqlCommand();
            objCommand->CommandText = sSql;
            objCommand->Connection = this->getObjConexion();
            // Ejecutar el comando y obtener el idMedico obtenido por la BD
            int idMedicoGenerado = Convert::ToInt32(objCommand->ExecuteScalar());
            //Insertamos medico_especialidad: 
            for each(Especialidad^ objEspecialidad in especialidades) {
                sSql = "Insert into medico_especialidad (idMedico, idEspecialidad)";
                sSql += " values(" + idMedicoGenerado + ", " + objEspecialidad->getIdEspecialidad() + ")";
                objCommand->CommandText = sSql;
                objCommand->Connection = this->getObjConexion();
                objCommand->ExecuteNonQuery();
            }
        }
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

String^ MedicoController::updateMedico(int idPersona, String^ apellidos, String^ nombres, int fechaNacimiento, String^ genero, String^ direccion, String^ telefonos, String^ email, String^ estadoCivil, float altura, String^ tipoDocumento, String^ numeroDocumento, int idMedico, String^ numeroColegioMedico, List<String^>^ certificaciones, List<Especialidad^>^ especialidades, List<int>^ idCitasAsignadas, List<Paciente^>^ pacientesAsociados) {
    String^ sMessageBox = "";
    try
    {
        PersonaController^ objControler = gcnew PersonaController();
        sMessageBox = objControler->updatePersona(idPersona, apellidos, nombres, fechaNacimiento, genero, direccion, telefonos, email, estadoCivil, altura, tipoDocumento, numeroDocumento);
        if (sMessageBox->Equals(""))
        {
            abrirConexion();
            // Serializar certificaciones
            String^ listCertificados;
            if (certificaciones->Count > 0) {
                listCertificados = String::Join(",", certificaciones);
            }
            //Insertamos la medico: idMedico no se remite, por cuanto el valor lo asigna la base de datos
            String^ sSql = "Update medico Set ";
            sSql += " idPersona = " + idPersona + ", ";
            sSql += " numeroColegioMedico = '" + numeroColegioMedico + "', ";
            sSql += " certificaciones = '" + listCertificados + "' ";
            sSql += " Where idMedico = " + idMedico + " ";
            SqlCommand^ objCommand = gcnew SqlCommand();
            objCommand->CommandText = sSql;
            objCommand->Connection = this->getObjConexion();
            // Ejecutar la sentencia
            objCommand->ExecuteNonQuery();

            //Eliminamos todos los registros relacionados a idMedico en la tabla medico_especialidad
            sSql = "Delete From medico_especialidad Where idMedico = " + idMedico + " " ;
            objCommand->CommandText = sSql;
            objCommand->Connection = this->getObjConexion();
            objCommand->ExecuteNonQuery();
            //Volvemos a insertar todos las especialidades del idMedico en medico_especialidad: 
            for each (Especialidad ^ objEspecialidad in especialidades) {
                sSql = "Insert into medico_especialidad (idMedico, idEspecialidad)";
                sSql += " values(" + idMedico + ", " + objEspecialidad->getIdEspecialidad() + ")";
                objCommand->CommandText = sSql;
                objCommand->Connection = this->getObjConexion();
                objCommand->ExecuteNonQuery();
            }
        }

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
    finally {
        cerrarConexion();
    }
    return sMessageBox;
}

String^ MedicoController::deleteMedico(int idMedico) {
    String^ sMessageBox = "";
    try
    {
        Medico^ objMedico = getMedicoById(idMedico);
        
        abrirConexion();
        SqlCommand^ objCommand = gcnew SqlCommand();

        //Tablas dependientes
        //Eliminamos todos los registros relacionados a idMedico en la tabla medico_especialidad
        String^ sSql = "Delete From medico_especialidad Where idMedico = " + idMedico + " ";
        objCommand->CommandText = sSql;
        objCommand->Connection = this->getObjConexion();
        objCommand->ExecuteNonQuery();

        //Registro
        //Eliminamos el registro relacionado a idMedico en la tabla medico
        sSql = "Delete From medico Where idMedico = " + idMedico + " ";
        objCommand->CommandText = sSql;
        objCommand->Connection = this->getObjConexion();
        objCommand->ExecuteNonQuery();

        cerrarConexion();

        //Analizar si tambien hay que eliminar al Padre, por tratrse de una herencia
        //Eliminamos el registro relacionado a idMedico en la tabla Persona
        PersonaController^ objController = gcnew PersonaController();
        sMessageBox = objController->deletePersona(objMedico->getIdPersona());
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