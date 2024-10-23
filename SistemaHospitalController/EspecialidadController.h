#pragma once

namespace SistemaHospitalController {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace SistemaHospitalModel;

	public ref class EspecialidadController {

	public:
		EspecialidadController();
		List<Especialidad^>^ listarEspecialidades();
		Especialidad^ buscarEspecialidadById(int idEspecialidad);
		Especialidad^ buscarEspecialidadByNombre(String^ sNombre);
		/****************************************************************************************************************************/
		/****************************************************************************************************************************/
		/****************************************************************************************************************************/
	};
}