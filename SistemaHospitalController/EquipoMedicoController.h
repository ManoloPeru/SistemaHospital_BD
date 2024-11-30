#pragma once
#include "BaseController.h"

namespace SistemaHospitalController {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace SistemaHospitalModel;

	public ref class EquipoMedicoController : public BaseController {
	public:
		EquipoMedicoController();
		List<EquipoMedico^>^ listarEquipoMedico();
		List<ReporteEquipoMedico^>^ contarCantidadEquipos();

		List<EquipoMedico^>^ listarEquiposMedicosxNombre(String^ nombre);
		List<EquipoMedico^>^ listarEquiposMedicosAll();
		EquipoMedico^ buscarEquipoMedicoById(int idEquipo);
		EquipoMedico^ buscarEquipoMedicoByNombre(String^ nombre);
		void registrarEquipoMedico(String^ nombre, String^ disponibilidad);
		void eliminarEquipoMedico(int idEquipo);
		void actualizarEquipoMedico(int idEquipo, String^ nombre, String^ disponibilidad);
	};
}