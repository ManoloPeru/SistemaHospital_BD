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
		Persona^ buscarPersonaById(int idPersona);
		Persona^ buscarPersonaByUsuario(String^ usuario, String^ contrasenia);
	};
}