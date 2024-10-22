#include "Especialidad.h"

namespace SistemaHospitalModel {

    // Constructor vacío
    Especialidad::Especialidad() {
        this->idEspecialidad = 0;
        this->nombre = "";
        this->descripcion = "";
    }

    // Constructor con parámetros
    Especialidad::Especialidad(int idEspecialidad, String^ nombre, String^ descripcion) {
        this->idEspecialidad = idEspecialidad;
        this->nombre = nombre;
        this->descripcion = descripcion;
    }

    // Métodos GET
    int Especialidad::getIdEspecialidad() {
        return this->idEspecialidad;
    }

    String^ Especialidad::getNombre() {
        return this->nombre;
    }

    String^ Especialidad::getDescripcion() {
        return this->descripcion;
    }

    // Métodos SET
    void Especialidad::setIdEspecialidad(int idEspecialidad) {
        this->idEspecialidad = idEspecialidad;
    }

    void Especialidad::setNombre(String^ nombre) {
        this->nombre = nombre;
    }

    void Especialidad::setDescripcion(String^ descripcion) {
        this->descripcion = descripcion;
    }
}
