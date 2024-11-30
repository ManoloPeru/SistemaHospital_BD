#include "EquipoMedico.h"

namespace SistemaHospitalModel {

	// Constructor vacío
	EquipoMedico::EquipoMedico() {
		this->idEquipo = 0;
		this->nombre = "";
		this->disponibilidad = "";
	}

	// Constructor con parámetros
	EquipoMedico::EquipoMedico(int idEquipo, String^ nombre, String^ disponibilidad) {
		this->idEquipo = idEquipo;
		this->nombre = nombre;
		this->disponibilidad = disponibilidad;
	}

	// Métodos GET
	int EquipoMedico::getIdEquipo() {
		return this->idEquipo;
	}

	String^ EquipoMedico::getNombre() {
		return this->nombre;
	}

	String^ EquipoMedico::getDisponibilidad() {
		return this->disponibilidad;
	}

	// Métodos SET
	void EquipoMedico::setIdEquipo(int idEquipo) {
		this->idEquipo = idEquipo;
	}

	void EquipoMedico::setNombre(String^ nombre) {
		this->nombre = nombre;
	}

	void EquipoMedico::setDisponibilidad(String^ disponibilidad) {
		this->disponibilidad = disponibilidad;
	}


	/* Metodos de la clase ReporteEquipoMedico */
		// Constructor vacío
	ReporteEquipoMedico::ReporteEquipoMedico() {
		this->equipo = "";
		this->cantidad = 0;
	}

	// Constructor con parámetros
	ReporteEquipoMedico::ReporteEquipoMedico(String^ equipo, int cantidad) {
		this->equipo = equipo;
		this->cantidad = cantidad;
	}

	// Métodos GET
	String^ ReporteEquipoMedico::getEquipo() {
		return this->equipo;
	}

	int ReporteEquipoMedico::getCantidad() {
		return this->cantidad;
	}
	// Métodos SET
	void ReporteEquipoMedico::setEquipo(String^ equipo) {
		this->equipo = equipo;
	}

	void ReporteEquipoMedico::setCantidad(int cantidad) {
		this->cantidad = cantidad;
	}
}

