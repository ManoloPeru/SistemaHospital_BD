#include "CitaController.h"
#include "PacienteController.h"
#include "MedicoController.h"

using namespace SistemaHospitalController;
using namespace System::IO; //Para leer archivos

CitaController::CitaController() {

}

// Método para listar Citas
List<Cita^>^ CitaController::listarCitas() {
    List<Cita^>^ listaCitas = gcnew List<Cita^>();
    array<String^>^ lineasArchivo = File::ReadAllLines("Citas.txt");
    String^ separadores = ";";
    String^ separadorLista = ",";
    for each (String ^ linea in lineasArchivo) {
        /*Voy a separar los datos de una linea en un arreglo de string*/
        array<String^>^ datos = linea->Split(separadores->ToCharArray());
        //Clase Persona
        int idCita = Convert::ToInt32(datos[0]);
        int idPaciente = Convert::ToInt32(datos[1]);
        PacienteController^ objPacienteController = gcnew PacienteController();
        Paciente^ paciente = objPacienteController->buscarPacienteById(idPaciente);
        int idMedico = Convert::ToInt32(datos[2]);
        MedicoController^ objMedicoController = gcnew MedicoController();
        Medico^ medico = objMedicoController->buscarMedicoById(idMedico);
        int fecha = Convert::ToInt32(datos[3]);
        String^ hora = datos[4];
        String^ proposito = datos[5];
        String^ resultado = datos[6];
        
               
        // Crear objeto Cita y añadir a la lista
        Cita^ cita = gcnew Cita();
        // Asignar propiedades de Persona
        cita->setIdCita(idCita);
        cita->setPaciente(paciente);
        cita->setMedico(medico);
        cita->setFecha(fecha);
        cita->setHora(hora);
        cita->setProposito(proposito);
        cita->setResultado(resultado);

        listaCitas->Add(cita);
    }
    return listaCitas;
}

// Método para buscar Cita por IdCita
Cita^ CitaController::buscarCitaById(int idCita) {
    List<Cita^>^ listaCitas = listarCitas();
    Cita^ citaEncontrado = gcnew Cita();
    for each (Cita ^ cita in listaCitas) {
        if (cita->getIdCita() == idCita) {
            // Verificar por ID de médico
            citaEncontrado->setPaciente(cita->getPaciente());
            citaEncontrado->setMedico(cita->getMedico());
            citaEncontrado->setFecha(cita->getFecha());
            citaEncontrado->setHora(cita->getHora());
            citaEncontrado->setProposito(cita->getProposito());
            citaEncontrado->setResultado(cita->getResultado());
            break;
        }
    }
    return citaEncontrado;
}

// Método para listar Citas por Fecha
List<Cita^>^ CitaController::listarCitasByFecha(int fecha) {
    List<Cita^>^ listaCitas = listarCitas();
    List<Cita^>^ citaEncontrados = gcnew List<Cita^>();
    for each (Cita ^ cita in listaCitas) {
        if (cita->getFecha() == fecha) {
            // Verificar por ID de médico
            citaEncontrados->Add(cita);
        }
    }
    return citaEncontrados;
}

//BD
List<Cita^>^ CitaController::selectCita(String^ fecha) {
    String^ sql = "SELECT c.idCita, p.apellidos + ' ' + p.nombres  as paciente, pp.apellidos + ' ' + pp.nombres as medico, c.hora ";
    sql += "FROM citaMedica c, paciente p, medico m, persona pp ";
    sql += "WHERE c.idPaciente = p.idPaciente AND c.idMedico = m.idMedico AND m.idPersona = pp.idPersona ";
    if (!fecha->Equals(""))
    {
        sql += "AND c.fecha = '" + fecha + "' ";
    }
    List<Cita^>^ listaCitas = gcnew List<Cita^>();
    abrirConexion();
    /*SqlCommand nos permite crear un objeto a trav�s del cual voy a definir una sentencia SQL*/
    SqlCommand^ objSentencia = gcnew SqlCommand();
    /*Aqui estoy indicando que mi sentencia se va a ejecutar en esa conexion de base de datos*/
    objSentencia->Connection = this->getObjConexion();
    /*Aqui voy a definir la sentencia SQL que voy a ejecutar*/
    objSentencia->CommandText = sql;
    /*Ahora para ejecutar voy a utilizar ExecuteReader cuando la sentencia es SELECT*/
    /*Para recuperar la informacion que me devuelve un select, utilizo SqlDataReader*/
    SqlDataReader^ objData = objSentencia->ExecuteReader();
    while (objData->Read()) {
        Cita^ objCita = gcnew Cita();
        objCita->setIdCita(safe_cast<int>(objData[0]));
        String^ nombrePaciente = safe_cast<String^>(objData[1]);
        String^ nombreMedico = safe_cast<String^>(objData[2]);
        objCita->setHora(safe_cast<String^>(objData[3]));
        objCita->setNombrePaciente(nombrePaciente);
        objCita->setNombreMedico(nombreMedico);
        listaCitas->Add(objCita);
    }
    objData->Close();
    cerrarConexion();
    return listaCitas;
}

void CitaController::insertCita(int idPaciente, int idMedico, String^ fecha, String^ hora) {
    abrirConexion();
    /*SqlCommand nos permite crear un objeto a trav�s del cual voy a definir una sentencia SQL*/
    SqlCommand^ objSentencia = gcnew SqlCommand();

    /*Aqui estoy indicando que mi sentencia se va a ejecutar en esa conexion de base de datos*/
    objSentencia->Connection = this->getObjConexion();

    /*Aqui voy a definir la sentencia SQL que voy a ejecutar*/

    objSentencia->CommandText = "insert into citaMedica (idMedico, idPaciente, fecha, hora) values (" + idMedico + ", " + idPaciente + ", '" + fecha + "','" + hora + "')";
    objSentencia->ExecuteNonQuery();
    cerrarConexion();
}

List<ReporteCita^>^ CitaController::contarCantidadCitas() {
    // SQL para contar citas agrupadas por fecha
    String^ sql = "SELECT fecha, COUNT(*) as cantidad FROM citaMedica GROUP BY fecha";

    // Lista que almacenará los reportes
    List<ReporteCita^>^ listaReporteCitas = gcnew List<ReporteCita^>();
    abrirConexion();
    SqlCommand^ objSentencia = gcnew SqlCommand(sql, this->getObjConexion());
    SqlDataReader^ objData = objSentencia->ExecuteReader();

    while (objData->Read()) {
        // Obtener los valores de fecha y cantidad
        String^ fecha = safe_cast<String^>(objData["fecha"]);
        int cantidad = safe_cast<int>(objData["cantidad"]);

        // Crear un objeto ReporteCita y agregarlo a la lista
        ReporteCita^ reporte = gcnew ReporteCita(fecha, cantidad);
        listaReporteCitas->Add(reporte);
    }

    objData->Close();
    cerrarConexion();
    return listaReporteCitas;
}