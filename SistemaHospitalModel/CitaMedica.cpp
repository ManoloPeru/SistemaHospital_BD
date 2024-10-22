#include "CitaMedica.h"

namespace SistemaHospitalModel {

    // Constructor vacío
    CitaMedica::CitaMedica() {
        this->idCita = 0;
        this->paciente = gcnew Paciente();
        this->medico = gcnew Medico();
        this->fecha = DateTime::Now;
        this->hora = TimeSpan::Zero;
        this->proposito = "";
        this->resultado = "";
        this->tratamientoProgramado = gcnew Tratamiento();
    }

    //// Constructor con parámetros: 
    CitaMedica::CitaMedica(int idCita, Paciente^ paciente, Medico^ medico, DateTime fecha, TimeSpan hora, String^ proposito, String^ resultado, Tratamiento^ tratamientoProgramado) {
        this->idCita = idCita;
        this->paciente = paciente;
        this->medico = medico;
        this->fecha = fecha;
        this->hora = hora;
        this->proposito = proposito;
        this->resultado = resultado;
        this->tratamientoProgramado = tratamientoProgramado;
    }

    // Métodos GET
    int CitaMedica::getIdCita() {
        return this->idCita;
    }

    Paciente^ CitaMedica::getPaciente() {
        return this->paciente;
    }

    Medico^ CitaMedica::getMedico() {
        return this->medico;
    }

    DateTime CitaMedica::getFecha() {
        return this->fecha;
    }

    TimeSpan CitaMedica::getHora() {
        return this->hora;
    }

    String^ CitaMedica::getProposito() {
        return this->proposito;
    }

    String^ CitaMedica::getResultado() {
        return this->resultado;
    }

    Tratamiento^ CitaMedica::getTratamientoProgramado() {
        return this->tratamientoProgramado;
    }

    // Métodos SET
    void CitaMedica::setIdCita(int idCita) {
        this->idCita = idCita;
    }

    void CitaMedica::setPaciente(Paciente^ paciente) {
        this->paciente = paciente;
    }

    void CitaMedica::setMedico(Medico^ medico) {
        this->medico = medico;
    }

    void CitaMedica::setFecha(DateTime fecha) {
        this->fecha = fecha;
    }

    void CitaMedica::setHora(TimeSpan hora) {
        this->hora = hora;
    }

    void CitaMedica::setProposito(String^ proposito) {
        this->proposito = proposito;
    }

    void CitaMedica::setResultado(String^ resultado) {
        this->resultado = resultado;
    }

    void CitaMedica::setTratamientoProgramado(Tratamiento^ tratamientoProgramado) {
        this->tratamientoProgramado = tratamientoProgramado;
    }
}
