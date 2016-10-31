/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package proxy_renew;
import java.net.*;
import java.io.*;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/**
 *
 * @author rayhan
 */
public class thread_proxy implements Runnable {


    public final int sleep_time;
    public final ServerSocket server_socket;
    //String res_address = "www.google.com";
    boolean permission = true;
    public thread_proxy(ServerSocket s)
    {
        server_socket = s;
        sleep_time = 100;
    }

    public void run()
    {
        InputStream fromClient;
        
        Socket clientSocket = null;

          String address =null;



        try{






       while(true){

        

        try {


           clientSocket = server_socket.accept();//accepting the request from the browser ...

                



            fromClient = clientSocket.getInputStream();


            InputStreamReader inputStreamReader = new InputStreamReader(fromClient);

               BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
                String command = bufferedReader.readLine();
              //  System.out.println("command>>"+command+" "+command.charAt(command.length()-10));
                if(command.charAt(command.length()-10)=='/'){
            address = command.substring(11,command.length()-10 );//this parses the original address e.g. www.facebook.com
            }
 else
                {
      address = command.substring(11,command.length()-9 );//this parses the original address e.g. www.facebook.com
            }

                for(int i=0;i<gui.counter;i++)
                {
                if(address.startsWith(gui.array[i+1]))
                {
                    permission = false;
                    break;
                }

                    else
                {
                    permission = true;
                }

                }

                if(permission){             //////////checking whether in the block list or not.....

            address = "http://"+address+"/";
            //System.out.println(address);
            URL url_to_server = new URL(address);


 //////////////////////////////////////////////////////////////////////////////////////////

            
            BufferedReader in = new BufferedReader(new InputStreamReader( url_to_server.openStream()));

            String inputLine;

            /////////////////////////////////////////////////////////////////////////////////////////////////////

            OutputStreamWriter out = new OutputStreamWriter(
                              clientSocket.getOutputStream());


                               PrintStream out_p = new PrintStream(clientSocket.getOutputStream());



            while ((inputLine = in.readLine()) != null)
            {
                out.write(inputLine);           
            }

            out.flush();
            in.close();
            out.close();

            //String val=in.toString();
           }

        else
    {
            System.out.println("Access to site is restricted by the administator...\nEnter another address...");
            OutputStreamWriter out = new OutputStreamWriter(
                              clientSocket.getOutputStream());
            out.write("OH NO!!!\nYOU ARE TRYING TO ENTER INTO A RESTRICTED SITE!!!\nBE FARE ATLEAST...");
            out.flush();
            out.close();

            JOptionPane.showMessageDialog(null, "Browser is trying to enter into a restricted site..","PROXY SERVER",JOptionPane.WARNING_MESSAGE);


    }

        }





        catch (Exception ex) {
            Logger.getLogger(proxy.class.getName()).log(Level.SEVERE, null, ex);
                             }






        }//while ends

       


          
        }
       
        finally{
                    
            try {
                clientSocket.close();
                server_socket.close();

            } catch (IOException ex) {
                Logger.getLogger(thread_proxy.class.getName()).log(Level.SEVERE, null, ex);
            }
               }
    }

}
