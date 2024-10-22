#pragma once

namespace SistemaHospitalModel {
    using namespace System; // Para tipos como String

    // Declaracion de la clase Persona
    public ref class Persona {
    protected:
        int idPersona;
        String^ apellidos;
        String^ nombres;
        int fechaNacimiento; //ejemplo: 20010118: 18 de Enero del 2001
        String^ genero;
        String^ direccion;
        String^ telefonos;
        String^ email;
        String^ estadoCivil;
        float altura;
        String^ tipoDocumento;
        String^ numeroDocumento;
        String^ usuario;
        String^ contrasenia;

    public:
        // Constructor vac�o
        Persona();

        // Constructor con todos los par�metros
        Persona(int idPersona, String^ apellidos, String^ nombres, int fechaNacimiento, String^ genero, String^ direccion, String^ telefonos, 
            String^ email, String^ estadoCivil, float altura, String^ tipoDocumento, String^ numeroDocumento, String^ usuario, String^ contrasenia);

        // Metodos GET
        int getIdPersona();
        String^ getApellidos();
        String^ getNombres();
        int getFechaNacimiento();
        String^ getGenero();
        String^ getDireccion();
        String^ getTelefonos();
        String^ getEmail();
        String^ getEstadoCivil();
        float getAltura();
        String^ getTipoDocumento();
        String^ getNumeroDocumento();
        String^ getUsuario();
        String^ getContrasenia();

        // Metodos SET
        void setIdPersona(int id);
        void setApellidos(String^ apellidos);
        void setNombres(String^ nombres);
        void setFechaNacimiento(int fechaNacimiento);
        void setGenero(String^ genero);
        void setDireccion(String^ direccion);
        void setTelefonos(String^ telefonos);
        void setEmail(String^ email);
        void setEstadoCivil(String^ estadoCivil);
        void setAltura(float altura);
        void setTipoDocumento(String^ tipoDocumento);
        void setNumeroDocumento(String^ numeroDocumento);
        void setUsuario(String^ usuario);
        void setContrasenia(String^ contrasenia);
    };
}

/*
CREATE TABLE persona (
    idPersona INT IDENTITY(1,1) PRIMARY KEY,  -- Campo Identity que incrementa autom�ticamente
    apellidos VARCHAR(30),          -- Apellidos de la persona (limite de 100 caracteres)
    nombres VARCHAR(30),            -- Nombres de la persona (limite de 100 caracteres)
    fechaNacimiento INT,             -- Fecha de nacimiento en formato YYYYMMDD (int)
    genero VARCHAR(10),              -- G�nero de la persona (Ej: "M", "F", etc.)
    direccion VARCHAR(100),          -- Direcci�n de la persona
    telefonos VARCHAR(50),                    -- N�meros de tel�fono (puede almacenar m�ltiples tel�fonos)
    email VARCHAR(50),                       -- Direcci�n de correo electr�nico
    estadoCivil VARCHAR(10),                  -- Estado civil (Ej: "Soltero", "Casado")
    altura FLOAT,                             -- Altura de la persona en metros
    tipoDocumento VARCHAR(10),                -- Tipo de documento (Ej: "DNI", "Pasaporte")
    numeroDocumento VARCHAR(8),              -- N�mero de documento
    usuario VARCHAR(20),             -- Nombre de usuario para autenticaci�n
    contrasenia VARCHAR(20)          -- Contrase�a para autenticaci�n
);
*/