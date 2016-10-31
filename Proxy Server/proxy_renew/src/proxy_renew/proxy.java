/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package proxy_renew;
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

//package final_proxy;

import java.io.*;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.*;
import java.util.logging.Level;
import java.util.logging.Logger;
/**
 *
 * @author rayhan
 */
public class proxy {
   static byte[] buffer = new byte[1000];
		int numberRead = 0;

		OutputStream toClient=null;
		static InputStream fromClient,from_remote_server;

    public static void worker() throws UnknownHostException{
       
        ServerSocket serverSocket = null;
        
        int port=gui.port;
        System.out.printf("---------------%d",port);
      try{
               serverSocket = new ServerSocket(port,100);
              
           }

        catch(IOException e)
                {
                    System.out.println("io exception...");
                }



          Thread thread = new Thread(new thread_proxy(serverSocket));
          thread.start();



       
    }
}
