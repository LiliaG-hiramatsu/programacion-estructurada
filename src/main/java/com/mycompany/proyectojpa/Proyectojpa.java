package com.mycompany.proyectojpa;

import com.mycompany.proyectojpa.logica.Alumno;
import com.mycompany.proyectojpa.logica.Controladora;
import com.mycompany.proyectojpa.logica.Cursado;
import com.mycompany.proyectojpa.logica.Inscripcion;
import java.util.ArrayList;
import java.util.Date;

// Claudia Bottero - Lilia García

public class Proyectojpa {

    public static void main(String[] args) {
        
        Controladora control = new Controladora();
        
        // Lista de alumnos
        ArrayList<Alumno> listaAlumnos = new ArrayList<>();
        
        // Creamos una inscripcion con lista de cursos
        Inscripcion insc1 = new Inscripcion(001, "Desarrollo de Software", new Date(), 123, listaAlumnos);
        
        // Guardar la inscripcion en la BBDD
        control.crearInscripcion(insc1);
        
        // Creamos lista de cursados
        ArrayList<Cursado> listaCursados = new ArrayList<>();
        
        // Creamos alumnos
        Alumno alu1 = new Alumno(42888555, "Juan", "Perez", new Date(), "Santa Fe 218", 26153472, insc1, listaCursados);
        Alumno alu2 = new Alumno(42444675, "Maria", "Gonzales", new Date(), "San Juan 812", 26159655, insc1, listaCursados);
        Alumno alu3 = new Alumno(42847699, "Gabriela", "Flores", new Date(), "Colon 152", 26157741, insc1, listaCursados);
        Alumno alu4 = new Alumno(42886655, "Facundo", "Rodriguez", new Date(), "Belgrano 1445", 26159632, insc1, listaCursados);
        
        // Guardar alumnos en la BBDD
        control.crearAlumno(alu1);
        control.crearAlumno(alu2);
        control.crearAlumno(alu3);
        control.crearAlumno(alu4);
        
        // Creamos lista de alumnos
        listaAlumnos.add(alu1);
        listaAlumnos.add(alu2);
        listaAlumnos.add(alu3);
        listaAlumnos.add(alu4);
        
        insc1.setListaAlumno(listaAlumnos);
        control.editarInscripcion(insc1);
        
        // Creacion de cursados
        Cursado curso1 = new Cursado(1456,9,alu1);
        Cursado curso2 = new Cursado(1578,7,alu1);
        Cursado curso3 = new Cursado(1986,10,alu1);
        Cursado curso4 = new Cursado(1456,6,alu1);
        
        // Guardar cursados en BBDD
        control.crearCursado(curso1);
        control.crearCursado(curso2);
        control.crearCursado(curso3);
        control.crearCursado(curso4);
        
        // Agregar cursados a la lista de cursados
        listaCursados.add(curso1);
        listaCursados.add(curso2);
        listaCursados.add(curso3);
        listaCursados.add(curso4);
        
        alu1.setListaCursados(listaCursados);
        control.editarAlumno(alu1);
        
        // Eliminar un alumno Facundo Rodriguez
        control.eliminarAlumno(42886655);
        
        // Editar alumno Gabriela Flores
        alu3.setAlu_apellido("Ortega");
        control.editarAlumno(alu3);
        
        // Busqueda de datos
        Alumno alu_bus = control.traerAlumno(42444675);
        System.out.println("----------BUSQUEDA INDIVIDUAL----------");
        System.out.println("El alumno es: " + alu_bus.toString());
        
        System.out.println("-----------BUSQUEDA DE TODOS------------");
        ArrayList<Alumno> listaAlumnos1 = control.traerListaAlumnos();
        for (Alumno al : listaAlumnos1) {
            System.out.println("El alumno es: " + al.toString());
        }
        System.out.println("-----------------------------------------");
    }
}
