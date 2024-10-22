#pragma once
#include "Paciente.h"

namespace SistemaHospitalModel {

    // Constructor vacío
    Paciente::Paciente() : Persona() {
        this->idPaciente = 0;
        this->numeroSeguroSocial = "";
        this->grupoSanguíneo = "";
        this->alergias = gcnew List<String^>();
        this->historialMedico = gcnew HistorialMedico();
        this->contactoEmergencia = "";
        this->diagnosticos = gcnew List<String^>();
    }

    // Constructor con parámetros
    Paciente::Paciente(int idPaciente, String^ numeroSeguroSocial, String^ grupoSanguíneo, List<String^>^ alergias, HistorialMedico^ historialMedico, String^ contactoEmergencia, List<String^>^ diagnosticos) : 
        Persona (idPersona, apellidos, nombres, fechaNacimiento, genero, direccion, telefonos,
            email, estadoCivil, altura, tipoDocumento, numeroDocumento, usuario, contrasenia)  {
        this->idPaciente = idPaciente;
        this->numeroSeguroSocial = numeroSeguroSocial;
        this->grupoSanguíneo = grupoSanguíneo;
        this->alergias = alergias;
        this->historialMedico = historialMedico;
        this->contactoEmergencia = contactoEmergencia;
        this->diagnosticos = diagnosticos;
    }

    // Métodos GET
    int Paciente::getIdPaciente() {
        return this->idPaciente;
    }

    String^ Paciente::getNumeroSeguroSocial() {
        return this->numeroSeguroSocial;
    }

    String^ Paciente::getGrupoSanguíneo() {
        return this->grupoSanguíneo;
    }

    List<String^>^ Paciente::getAlergias() {
        return this->alergias;
    }
    
    HistorialMedico^ Paciente::getHistorialMedico() {
        return this->historialMedico;
    }
    
    String^ Paciente::getContactoEmergencia() {
        return this->contactoEmergencia;
    }

    List<String^>^ Paciente::getDiagnosticos() {
        return this->diagnosticos;
    }

    // Métodos SET
    void Paciente::setIdPaciente(int idPaciente) {
        this->idPaciente = idPaciente;
    }

    void Paciente::setNumeroSeguroSocial(String^ numeroSeguroSocial) {
        this->numeroSeguroSocial = numeroSeguroSocial;
    }

    void Paciente::setGrupoSanguíneo(String^ grupoSanguíneo) {
        this->grupoSanguíneo = grupoSanguíneo;
    }

    void Paciente::setAlergias(List<String^>^ alergias) {
        this->alergias = alergias;
    }
    
    void Paciente::setHistorialMedico(HistorialMedico^ historialMedico) {
        this->historialMedico = historialMedico;
    }
    
    void Paciente::setContactoEmergencia(String^ contactoEmergencia) {
        this->contactoEmergencia = contactoEmergencia;
    }

    void Paciente::setDiagnosticos(List<String^>^ diagnosticos) {
        this->diagnosticos = diagnosticos;
    }
}
