#pragma once
#include "BaseController.h"

namespace SistemaHospitalController {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace SistemaHospitalModel;

	public ref class PacienteController : public BaseController {

	public:
		PacienteController();
		List<Paciente^>^ listarPacientes();
		Paciente^ buscarPacienteById(int idPaciente);
		/****************************************************************************************************************************/
		/****************************************************************************************************************************/
		/****************************************************************************************************************************/
		//Operaciones con Base de Datos
		List<Paciente^>^ selectPacientes();
		List<Paciente^>^ selectPacientesByApellido(String^ apellido);
		Paciente^ getPacienteById(int idPaciente);
		String^ insertPaciente(int idPaciente, String^ apellidos, String^ nombres, int fechaNacimiento, String^ genero, String^ direccion, String^ telefonos, String^ email, String^ estadoCivil, float altura, String^ tipoDocumento, String^ numeroDocumento);
		String^ updatePaciente(int idPaciente, String^ apellidos, String^ nombres, int fechaNacimiento, String^ genero, String^ direccion, String^ telefonos, String^ email, String^ estadoCivil, float altura, String^ tipoDocumento, String^ numeroDocumento);
		String^ deletePaciente(int idPaciente);
	};
}