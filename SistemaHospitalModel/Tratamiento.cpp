#include "Tratamiento.h"

namespace SistemaHospitalModel {

    // Constructor vacío
    Tratamiento::Tratamiento() {
        this->idTratamiento = 0;
        this->idMedicoAsignado = 0;
        this->procedimientos = gcnew List<Procedimiento^>();
        this->estado = "";
    }

    // Constructor con parámetros
    Tratamiento::Tratamiento(int idTratamiento, int idMedicoAsignado, List<Procedimiento^>^ procedimientos, String^ estado) {
        this->idTratamiento = idTratamiento;
        this->idMedicoAsignado = idMedicoAsignado;
        this->procedimientos = procedimientos;
        this->estado = estado;
    }

    // Métodos GET
    int Tratamiento::getIdTratamiento() {
        return this->idTratamiento;
    }

    int Tratamiento::getidMedicoAsignado() {
        return this->idMedicoAsignado;
    }

    List<Procedimiento^>^ Tratamiento::getProcedimientos() {
        return this->procedimientos;
    }

    String^ Tratamiento::getEstado() {
        return this->estado;
    }

    // Métodos SET
    void Tratamiento::setIdTratamiento(int idTratamiento) {
        this->idTratamiento = idTratamiento;
    }

    void Tratamiento::setidMedicoAsignado(int idMedicoAsignado) {
        this->idMedicoAsignado = idMedicoAsignado;
    }

    void Tratamiento::setProcedimientos(List<Procedimiento^>^ procedimientos) {
        this->procedimientos = procedimientos;
    }

    void Tratamiento::setEstado(String^ estado) {
        this->estado = estado;
    }
}
