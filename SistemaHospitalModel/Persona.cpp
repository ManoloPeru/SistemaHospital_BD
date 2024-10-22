#pragma once
#include "Persona.h"

namespace SistemaHospitalModel {

    // Constructor vacío
    Persona::Persona() {
        this->idPersona = 0;
        this->apellidos = "";
        this->nombres = "";
        this->fechaNacimiento = 0;
        this->genero = "";
        this->direccion = "";
        this->telefonos = "";
        this->email = "";
        this->estadoCivil = "";
        this->altura = 0.0f;
        this->tipoDocumento = "";
        this->numeroDocumento = "";
        this->usuario = "";
        this->contrasenia = "";
    }

    // Constructor con parámetros
    Persona::Persona(int idPersona, String^ apellidos, String^ nombres, int fechaNacimiento, String^ genero, String^ direccion, String^ telefonos,
        String^ email, String^ estadoCivil, float altura, String^ tipoDocumento, String^ numeroDocumento, String^ usuario, String^ contrasenia) {
        this->idPersona = idPersona;
        this->apellidos = apellidos;
        this->nombres = nombres;
        this->fechaNacimiento = fechaNacimiento;
        this->genero = genero;
        this->direccion = direccion;
        this->telefonos = telefonos;
        this->email = email;
        this->estadoCivil = estadoCivil;
        this->altura = altura;
        this->tipoDocumento = tipoDocumento;
        this->numeroDocumento = numeroDocumento;
        this->usuario = usuario;
        this->contrasenia = contrasenia;
    }

    // Metodos GET
    int Persona::getIdPersona() {
        return this->idPersona;
    }

    String^ Persona::getApellidos() {
        return this->apellidos;
    }

    String^ Persona::getNombres() {
        return this->nombres;
    }

    int Persona::getFechaNacimiento() {
        return this->fechaNacimiento;
    }

    String^ Persona::getGenero() {
        return this->genero;
    }

    String^ Persona::getDireccion() {
        return this->direccion;
    }

    String^ Persona::getTelefonos() {
        return this->telefonos;
    }

    String^ Persona::getEmail() {
        return this->email;
    }

    String^ Persona::getEstadoCivil() {
        return this->estadoCivil;
    }

    float Persona::getAltura() {
        return this->altura;
    }

    String^ Persona::getTipoDocumento() {
        return this->tipoDocumento;
    }

    String^ Persona::getNumeroDocumento() {
        return this->numeroDocumento;
    }

    String^ Persona::getUsuario() {
        return this->usuario;
    }

    String^ Persona::getContrasenia() {
        return this->contrasenia;
    }


    // Metodos SET
    void Persona::setIdPersona(int id) {
        this->idPersona = id;
    }

    void Persona::setApellidos(String^ apellidos) {
        this->apellidos = apellidos;
    }

    void Persona::setNombres(String^ nombres) {
        this->nombres = nombres;
    }

    void Persona::setFechaNacimiento(int fechaNacimiento) {
        this->fechaNacimiento = fechaNacimiento;
    }

    void Persona::setGenero(String^ genero) {
        this->genero = genero;
    }

    void Persona::setDireccion(String^ direccion) {
        this->direccion = direccion;
    }

    void Persona::setTelefonos(String^ telefonos) {
        this->telefonos = telefonos;
    }

    void Persona::setEmail(String^ email) {
        this->email = email;
    }

    void Persona::setEstadoCivil(String^ estadoCivil) {
        this->estadoCivil = estadoCivil;
    }

    void Persona::setAltura(float altura) {
        this->altura = altura;
    }

    void Persona::setTipoDocumento(String^ tipoDocumento) {
        this->tipoDocumento = tipoDocumento;
    }

    void Persona::setNumeroDocumento(String^ numeroDocumento) {
        this->numeroDocumento = numeroDocumento;
    }

    void Persona::setUsuario(String^ usuario) {
        this->usuario = usuario;
    }

    void Persona::setContrasenia(String^ contrasenia) {
        this->contrasenia = contrasenia;
    }
}
