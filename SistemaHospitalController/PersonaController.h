#pragma once
#include "BaseController.h"

namespace SistemaHospitalController {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace SistemaHospitalModel;

	public ref class PersonaController : public BaseController {

	public:
		PersonaController();
		List<Persona^>^ listarPersonas();
		/*****************************************************************************************/
		/*****************************************************************************************/
		/*****************************************************************************************/
		//Operaciones con Base de Datos
		String^ insertPersona(int idPersona, String^ apellidos, String^ nombres, int fechaNacimiento, String^ genero, String^ direccion, String^ telefonos, String^ email, String^ estadoCivil, float altura, String^ tipoDocumento, String^ numeroDocumento);
		String^ updatePersona(int idPersona, String^ apellidos, String^ nombres, int fechaNacimiento, String^ genero, String^ direccion, String^ telefonos, String^ email, String^ estadoCivil, float altura, String^ tipoDocumento, String^ numeroDocumento);
		String^ deletePersona(int idPersona);
		Persona^ buscarPersonaById(int idPersona);
		Persona^ buscarPersonaByUsuario(String^ usuario, String^ contrasenia);
	};
}