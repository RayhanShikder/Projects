/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package torrent.server;

/**
 *
 * @author shiku
 */

import com.sun.imageio.plugins.common.InputStreamAdapter;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.PrintWriter;
import java.io.Serializable;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.logging.Level;
import java.util.logging.Logger;
import sun.security.util.Password;



/**
 * A multithreaded chat room server.  When a client connects the
 * server requests a screen name by sending the client the
 * text "SUBMITNAME", and keeps requesting a name until
 * a unique one is received.  After a client submits a unique
 * name, the server acknowledges with "NAMEACCEPTED".  Then
 * all messages from that client will be broadcast to all other
 * clients that have submitted a unique screen name.  The
 * broadcast messages are prefixed with "MESSAGE ".
 *
 * Because this is just a teaching example to illustrate a simple
 * chat server, there are a few features that have been left out.
 * Two are very useful and belong in production code:
 *
 *     1. The protocol should be enhanced so that the client can
 *        send clean disconnect messages to the server.
 *
 *     2. The server should do some logging.
 */
public class Torrent_Server {

    /**
     * The port that the server listens on.
     */
    private static final int PORT = 9004;

    /*
 * some global data
 */

private static String[] user_name={"rayhan","tanmim","maruf"};
private static String[] pass_word={"11","111","1111"};
 public  static ArrayList<String> allUserName= new ArrayList<String>();
    public  static ArrayList<String> allPassword= new ArrayList<String>();
    public static ArrayList<String> allFiles = new ArrayList<String>();
   

    /**
     * The set of all names of clients in the chat room.  Maintained
     * so that we can check that new clients are not registering name
     * already in use.
     */
    private static HashSet<String> names = new HashSet<String>();
    //private static ArrayList<ArrayList<byte[]>> buffer_list = new ArrayList<ArrayList<byte[]>>(10);

    /**
     * The set of all the print writers for all the clients.  This
     * set is kept so we can easily broadcast messages.
     */
    private static ArrayList<ObjectOutputStream> writers = new ArrayList<ObjectOutputStream>();
    private static ArrayList<String> Online_clients = new ArrayList<String>();

    /**
     * The appplication main method, which just listens on a port and
     * spawns handler threads.
     */
    public static void main(String[] args) throws Exception {
        init();
        read_user_info();
        System.out.println("The torrent server is running.");
        ServerSocket listener = new ServerSocket(PORT);
        try {
            while (true) {
                new Handler(listener.accept()).start();
            }
        } finally {
            listener.close();
        }
    }

    /*
     * Initialize the user information (usernames,password)
     */
    public static void init()
    {
        user_info user;
        try{

            File file=new File("user_info_serializable.txt");
            /*
            if(!file.exists()){
                file.createNewFile();
            }*/
        FileOutputStream fos = new FileOutputStream(file);
        ObjectOutputStream oos = new ObjectOutputStream(fos);

        for(int i=0;i<user_name.length;i++)
        {
            user = new user_info(user_name[i],pass_word[i]);
            oos.writeObject(user);
        }

        //oos.writeObject(object1);
        oos.flush();
        oos.close();
        }
        catch(Exception e)
        {
            System.out.println("Exception during serialization: " + e);
            System.exit(0);
        }
    }
    // Method init() ends here...


    //Method receive_and_send starts here...

    public static void receive_and_send(ObjectInputStream in,ObjectOutputStream out,String receiver,String file_name,String file_size_str)
    {
       
int count;

try{
    int file_read_length =0;

    //////////////////////////////////////////////

   
          ObjectOutputStream receiver_stream = writers.get(Online_clients.indexOf(receiver));
          
    
          int file_size = Integer.parseInt(file_size_str);

    
            File myFile = new File("C:\\Users\\shiku\\Documents\\servers_folder\\new.txt");

            if(!myFile.exists()){//check if file exists
                myFile.delete();
                myFile.createNewFile();
            }else{
                System.out.println("This File exists");
            }

            System.out.println("New file has been created!");
            FileOutputStream myFileOut = new FileOutputStream(myFile);
            ObjectInputStream myInStream = in;

             byte[] buffer = new byte[1024];
             byte[] full_buffer = new byte[file_size];

            int bytesReceived = 0;
            int totalReceived =0;

receiver_stream.writeObject("Receive your file...");
    receiver_stream.writeObject(file_name);
    receiver_stream.writeObject(file_size_str);

            /*while(myInStream.available()>0) {
                bytesReceived = myInStream.read(buffer);
                totalReceived = totalReceived + bytesReceived;
                if(totalReceived>file_size)
                {
                    receiver_stream.write(buffer,0, file_size - (totalReceived - 1024));
                  //  myFileOut.write(buffer, 0, file_size - (totalReceived - 1024));
                    receiver_stream.flush();
                }
                else{
                    receiver_stream.write(buffer,0,bytesReceived);
                   receiver_stream.flush();
                    //myFileOut.write(buffer,0,bytesReceived);
                
                }
                receiver_stream.reset();
                System.out.println("$$");
                


            }*/

      while(totalReceived<file_size)
            {
                bytesReceived = myInStream.read(buffer);
               // receiver_stream.write(buffer);
                for(int i=0,j=totalReceived;bytesReceived>0 && i<bytesReceived && j<file_size;i++,j++){full_buffer[j]=buffer[i];}
                if(bytesReceived>0)
                totalReceived = totalReceived + bytesReceived;
                bytesReceived =0;
                System.out.println(totalReceived);

               //receiver_stream.flush();
               // receiver_stream.reset();
                if(totalReceived>file_size)break;
             }



            System.out.println(myInStream.available()+" total received "+totalReceived);
            System.out.println(full_buffer);

            receiver_stream.write(full_buffer);

           receiver_stream.flush();
           
          //  myFileOut.close();


            /////////////////////////////////////////
/*
            FileInputStream myFileIn = new FileInputStream(myFile);
            byte[] buffer_rcvr = new byte[1024];
            int bytesRead = 0;
            int totalRead= 0;

            /*out_stream.writeObject("Take Your File...");
        out_stream.writeObject(receiver);
        out_stream.writeObject(file_path);
        out_stream.writeObject(myFile.length());

receiver_stream.writeObject("Receive your file...");
    receiver_stream.writeObject(file_name);
    receiver_stream.writeObject(file_size_str);

            while(myFileIn.available()>0)
            {
                bytesRead = myFileIn.read(buffer);
                receiver_stream.write(buffer);
                totalRead = totalRead + bytesRead;
                bytesRead =0;
                System.out.println(totalRead);
                receiver_stream.reset();
             }
        System.out.println("Total sent "+totalRead);
 */
                //////////////////////////////////////////////






    /////////////////////////////////////////////////


    System.out.println("File sent to client successfully...");


        }
catch(Exception ex)
{
    ex.printStackTrace();
    System.out.println("error receiving file!!!");
}
finally{
    return;
}
//fos.close();
//socket.close();
    }


    //Method receive_and_send ends here...






    /*
     * read the user informations from serializable file
     */
    
    private static void read_user_info()
    {
        try {
user_info object2;
FileInputStream fis = new FileInputStream("user_info_serializable.txt");
ObjectInputStream ois = new ObjectInputStream(fis);

for(int i=0;i<user_name.length;i++){
object2 = (user_info)ois.readObject();
allUserName.add(object2._username);
allPassword.add(object2._password);
System.out.println("Username: "+object2._username+" "+"password: "+object2._password);

}
ois.close();
//System.out.println("object2: " + object2);
}
catch(Exception e) {
System.out.println("Exception during deserialization: " +
e);
System.exit(0);
} 
        
    }


    /*
     *A serializable class for storing username and password
     *
     */

    public static class user_info implements Serializable{
        private String _username;
        private String _password;

        public user_info(String username,String password)
        {
            this._username = username;
            this._password = password;

        }
    }


    /**
     * A handler thread class.  Handlers are spawned from the listening
     * loop and are responsible for a dealing with a single client
     * and broadcasting its messages.
     */
    private static class Handler extends Thread {
        private String name;
        private Socket socket;
        private BufferedReader in;
        private PrintWriter out;
           ObjectInputStream ob_in_stream;
                ObjectOutputStream ob_out_stream;


        /**
         * Constructs a handler thread, squirreling away the socket.
         * All the interesting work is done in the run method.
         */
        public Handler(Socket socket) {
            this.socket = socket;
        }

        /**
         * Services this thread's client by repeatedly requesting a
         * screen name until a unique one has been submitted, then
         * acknowledges the name and registers the output stream for
         * the client in a global set, then repeatedly gets inputs and
         * broadcasts them.
         */
        @Override
        public void run() {
            String user_name = null;
            try {

                // Create character streams for the socket.
               // in = new BufferedReader(new InputStreamReader(
                 //   socket.getInputStream()));
                System.out.println("------------------");

                ArrayList<String> in_List;
                ob_in_stream = new ObjectInputStream(socket.getInputStream());
                ob_out_stream = new ObjectOutputStream(socket.getOutputStream());
              
             //user_info users_data = new user_info("rrr","111");
                   // out.println("SUBMITNAME");
                    user_name =  ob_in_stream.readObject().toString();
                    String pass_word = ob_in_stream.readObject().toString();
                   if(allUserName.contains(user_name) && allPassword.get(allUserName.indexOf(user_name)).equals(pass_word))
                   {
                           System.out.println("Logged in...");
                           ob_out_stream.writeObject("Successfull...");
                  
                   }
                    else
                   {
                        System.out.println("Invalid login...");
                        ob_out_stream.writeObject("Unsuccessfull...");

                    }

                    System.out.println("name-- "+user_name+" password: "+pass_word);

                 //   if(users_data._username.equals("rayhan"))break;
               // }

System.out.println("------------------");
in_List = new ArrayList<String>();

for(int i=0;i<allFiles.size();i++)
{
    in_List.add(allFiles.get(i));
}
ob_out_stream.writeObject("Shared_Files...");
ob_out_stream.writeObject(in_List);
System.out.println("Initially shared "+in_List.size()+" files...");
in_List.clear();

  writers.add(ob_out_stream);
  Online_clients.add(user_name);
    
                // Now that a successful name has been chosen, add the
                // socket's print writer to the set of all writers so
                // this client can receive broadcast messages.
               // out.println("NAMEACCEPTED");
               // writers.add(out);

                // Accept messages from this client and broadcast them.
                // Ignore other clients that cannot be broadcasted to.

                boolean server_stream_flag=true;
                while (server_stream_flag) {
                     String input = ob_in_stream.readObject().toString();
                    if (input.equals("Sharable_Files")) {
                        System.out.println("yes i got it...." + user_name+" >>");
                       in_List = (ArrayList<String>)ob_in_stream.readObject();
                       for(int i=0;i<in_List.size();i++)
                       {
                          // System.out.println(i+": "+in_List.get(i));
                           allFiles.add(in_List.get(i).toString() +"  ------    "+user_name);
                          //  System.out.println(i+": "+allFiles.get(i));

                       }
                       in_List.clear();
                       in_List = new ArrayList<String>();
                       for(int i=0;i<allFiles.size();i++)
                       {
                           in_List.add(allFiles.get(i));
                           System.out.print(">>> "+allFiles.get(i));
                       }
                       for (ObjectOutputStream writer : writers) {
                        writer.writeObject("Shared_Files...");
                        writer.writeObject(in_List);
                        System.out.println(in_List.size()+ " files written...");

                    }
                       

                    }
                else if(input.equals("Download for me..."))
                    {
                    String dwnld_request = ob_in_stream.readObject().toString();
                    String owner_client = dwnld_request.substring(dwnld_request.indexOf("------")+10);
                    String file_to_download = dwnld_request.substring(0,dwnld_request.indexOf("   $$$"));
                    writers.get(Online_clients.indexOf(owner_client)).writeObject("Give me a file...");
                    writers.get(Online_clients.indexOf(owner_client)).writeObject(file_to_download);
                    writers.get(Online_clients.indexOf(owner_client)).writeObject(user_name);




 //                   writers.get(Online_clients.indexOf(owner_client)).writeObject("Give "+ user_name + " this file,please...");


                        System.out.println("Download request received..."+file_to_download+"...");


                    }
                    else if(input.equals("Take Your File..."))
                    {
                        System.out.println("receiving file and sending it...");
                        String receiver = ob_in_stream.readObject().toString();
                        String file_name = ob_in_stream.readObject().toString();
                        String file_size = ob_in_stream.readObject().toString();
                        //int file_size = Integer.parseInt( ob_in_stream.readObject().toString());
                        System.out.println("file size ..."+file_size);
                        receive_and_send(ob_in_stream, ob_out_stream,receiver,file_name,file_size);

                    }
                else if(input.equals("GoodBye..."))
                        {
                    String owner_client;

                            in_List.clear();
                       in_List = new ArrayList<String>();

                    int l = allFiles.size();
                    for(int i=0;i<l;i++){
                     owner_client = allFiles.get(i).toString().substring(allFiles.get(i).toString().indexOf("------")+10);
                    if(!owner_client.equals(user_name))in_List.add(allFiles.get(i));
                    System.out.println("@@!!@@ "+owner_client+" "+i+" total size "+allFiles.size());
                            }
                     System.out.println("Eikhane aisi...");


                        System.out.println("Eikhane aisi...");
                      allFiles.clear();
                      allFiles = new ArrayList<String>();

                       for(int i=0;i<in_List.size();i++)
                       {
                           allFiles.add(in_List.get(i));
                           System.out.print(">>> "+in_List.get(i));
                       }
 System.out.println("Eikhane aisi...");
                      
                       for (ObjectOutputStream writer : writers) {
                        writer.writeObject("Shared_Files...");
                        if(in_List==null)writer.writeObject(null);
                        else
                        writer.writeObject(in_List);
                        System.out.println(in_List.size()+ " files written...");

                    }

                            ob_out_stream.writeObject("GoodBye..");
                            server_stream_flag=false;
                            System.out.println("GoodBye "+user_name);
                         }
                    /*for (PrintWriter writer : writers) {
                        writer.println("MESSAGE " + name + ": " + input);
                    }*/
                }
            } catch (Exception ex) {
                System.out.println("Socket Error...............");
                //Logger.getLogger(Torrent_Server.class.getName()).log(Level.SEVERE, null, ex);
            } finally {
                // This client is going down!  Remove its name and its print
                // writer from the sets, and close its socket.
                if (name != null) {
                    names.remove(name);

                }
                if (ob_out_stream != null) {
                    writers.remove(ob_out_stream);
                    
                }
                if(user_name !=null)
                {
                     Online_clients.remove(user_name);
                }
                try {
                    socket.close();
                } catch (IOException e) {
                    System.out.println("Socket Error!!!");
                }
            }
        }
    }
}