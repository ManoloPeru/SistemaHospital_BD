#include "Medico.h"

namespace SistemaHospitalModel {

    // Constructor vacío
    Medico::Medico() : Persona() {
        this->idMedico = 0;
        this->numeroColegioMedico = "";
        this->certificaciones = gcnew List<String^>();
        this->especialidades = gcnew List<Especialidad^>();
        this->idCitasAsignadas = gcnew List<int>();
        this->pacientesAsociados = gcnew List<Paciente^>();
    }

    // Constructor con parámetros
    Medico::Medico(int idMedico, String^ numeroColegioMedico, List<String^>^ certificaciones, List<Especialidad^>^ especialidades, List<int>^ idCitasAsignadas, List<Paciente^>^ pacientesAsociados)
        : Persona(idPersona, apellidos, nombres, fechaNacimiento, genero, direccion, telefonos,
            email, estadoCivil, altura, tipoDocumento, numeroDocumento, usuario, contrasenia) {
        this->idMedico = idMedico;
        this->numeroColegioMedico = numeroColegioMedico;
        this->certificaciones = certificaciones;
        this->especialidades = especialidades;
        this->idCitasAsignadas = idCitasAsignadas;
        this->pacientesAsociados = pacientesAsociados;
    }

    // Métodos GET
    int Medico::getIdMedico() {
        return this->idMedico;
    }

    String^ Medico::getNumeroColegioMedico() {
        return this->numeroColegioMedico;
    }

    List<String^>^ Medico::getCertificaciones() {
        return this->certificaciones;
    }

    List<Especialidad^>^ Medico::getEspecialidades() {
        return this->especialidades;
    }

    List<int>^ Medico::getidCitasAsignadas() {
        return this->idCitasAsignadas;
    }

    List<Paciente^>^ Medico::getPacientesAsociados() {
        return this->pacientesAsociados;
    }

    // Métodos SET
    void Medico::setIdMedico(int idMedico) {
        this->idMedico = idMedico;
    }

    void Medico::setNumeroColegioMedico(String^ numeroColegioMedico) {
        this->numeroColegioMedico = numeroColegioMedico;
    }

    void Medico::setCertificaciones(List<String^>^ certificaciones) {
        this->certificaciones = certificaciones;
    }

    void Medico::setEspecialidades(List<Especialidad^>^ especialidades) {
        this->especialidades = especialidades;
    }

    void Medico::setidCitasAsignadas(List<int>^ idCitasAsignadas) {
        this->idCitasAsignadas = idCitasAsignadas;
    }

    void Medico::setPacientesAsociados(List<Paciente^>^ pacientesAsociados) {
        this->pacientesAsociados = pacientesAsociados;
    }
}
