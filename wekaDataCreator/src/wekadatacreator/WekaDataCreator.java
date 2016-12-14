/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package wekadatacreator;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;

/**
 *
 * @author Rayhan
 */
public class WekaDataCreator {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        
         boolean flag = false;
        ArrayList<String> steps = new ArrayList<String>();
        File fin = new File("input.txt");
        FileInputStream fis = new FileInputStream(fin);
        PrintWriter writer = new PrintWriter("output.arff", "UTF-8");
        //Construct BufferedReader from InputStreamReader
	BufferedReader br = new BufferedReader(new InputStreamReader(fis));
//        BufferedReader br = new BufferedReader(new InputStreamReader(getClass().getResourceAsStream("/resources/questions.txt")));

        
   writer.println("@RELATION UserIDentification");

   writer.println("@ATTRIBUTE a  NUMERIC");
   writer.println("@ATTRIBUTE b   NUMERIC");
   writer.println("@ATTRIBUTE c  NUMERIC");
   writer.println("@ATTRIBUTE d   NUMERIC");
   writer.println("@ATTRIBUTE e  NUMERIC");
   writer.println("@ATTRIBUTE f   NUMERIC");
   writer.println("@ATTRIBUTE g  NUMERIC");
   writer.println("@ATTRIBUTE h   NUMERIC");
   writer.println("@ATTRIBUTE i  NUMERIC");
   writer.println("@ATTRIBUTE j   NUMERIC");
   writer.println("@ATTRIBUTE k  NUMERIC");
   writer.println("@ATTRIBUTE l   NUMERIC");
   writer.println("@ATTRIBUTE m  NUMERIC");
   writer.println("@ATTRIBUTE n   NUMERIC");
   writer.println("@ATTRIBUTE o  NUMERIC");
   writer.println("@ATTRIBUTE p   NUMERIC");
   writer.println("@ATTRIBUTE q  NUMERIC");
   
   writer.println("@ATTRIBUTE class { Happy, Inspiring,  Sympathy, Disgust, Fear}"); //here the input file consists of data from only these 5 emotional states.
                                                                                     // You need to provide the appropriate list of emotions here
   
   writer.println();
   writer.println("@DATA");
        String line = null;
        int newline_count = 0;
        String str = "";


        while ((line = br.readLine()) != null) {

            if (!line.equals("")) {
                String[] nLine = line.split(" ");
                
                    for(int i=0;i<nLine.length;i++)
                    {
    //                    System.out.print();
                        if(i<17 || i==nLine.length-1)
                        {
                            if(i>0)writer.print(",");
                            writer.print(nLine[i]);
                        }
                    }

                    writer.println();
                 

            }
             





        }
         writer.close();

        
    }
    
}
