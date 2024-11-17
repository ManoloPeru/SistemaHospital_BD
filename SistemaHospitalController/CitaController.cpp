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