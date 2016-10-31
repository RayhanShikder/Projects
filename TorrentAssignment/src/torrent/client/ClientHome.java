/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * ClientHome.java
 *
 * Created on Nov 26, 2013, 11:09:18 AM
 */

package torrent.client;

import java.awt.Component;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultListModel;
import javax.swing.JCheckBox;
import javax.swing.JFileChooser;
import javax.swing.JList;

/**
 *
 * @author shiku
 */
public class ClientHome extends javax.swing.JFrame {

   private static Socket socket;
   private static ObjectInputStream in_stream;
   private static ObjectOutputStream out_stream;
   private static DefaultListModel sample_Model_client = new DefaultListModel();
   private static DefaultListModel sample_Model_server = new DefaultListModel();


    private static ArrayList<String> file_names_client = new ArrayList<String>();
    private static ArrayList<String> file_names_server = new ArrayList<String>();
    private static ArrayList< Integer > file_size_client = new ArrayList<Integer>();
    private static File[] listOfFiles;
    private static String Base_Path;
    /** Creates new form ClientHome */
    public ClientHome(Socket socket_client,ObjectInputStream in, ObjectOutputStream out,String Client_name,String path) {

        //clientName.setText("asldkf");
        System.out.println("from clientHome: "+Client_name);
        socket = socket_client;
        in_stream = in;
        out_stream = out;
        
          Base_Path = "C:\\Users\\shiku\\Documents\\";
        Base_Path = Base_Path+path;
        System.out.println("Path is : "+Base_Path);
  File folder = new File(Base_Path);
  listOfFiles = folder.listFiles();
  //file_names = new String[listOfFiles.length];
  
System.out.println("file number: "+listOfFiles.length);
  for (int i = 0; i < listOfFiles.length; i++)
  {

   if (listOfFiles[i].isFile())
  {
   file_names_client.add(listOfFiles[i].getName());
   file_size_client.add((int)listOfFiles[i].length());
   sample_Model_client.addElement(listOfFiles[i].getName());
   //sample_Model.addElement(new JCheckBox());
   //System.out.println(file_names.get(i));
      }
  }

try{
String rcv = in_stream.readObject().toString();
if(rcv.equals("Shared_Files...")){

    file_names_server = (ArrayList<String>)in_stream.readObject();
System.out.println("Initially received "+file_names_server.size()+" files...");

   if(file_names_server!=null){
      for(int i=0;i<file_names_server.size();i++){
       sample_Model_server.addElement(file_names_server.get(i));
       }
   }

 else sample_Model_server.addElement("");
        }
        }
catch(Exception ey)
{
    System.out.println("exception from client occured...");
        }
        


    initComponents();
    String[] x = (String[])file_names_client.toArray(new String[file_names_client.size()]);

       jList1.setModel(sample_Model_client);
       jList_files_from_server.setModel(sample_Model_server);
       clientName.setText(Client_name);
       //JCheckBox xy = new JCheckBox("asld");
      // jList1.add(xy);
     //  run();
       
   
    }


    //Method for sending file...


    public static void send_file(String file_path,String receiver) throws IOException
    {
        String My_Path = Base_Path +"\\"+file_path;
        System.out.println("Path of file is : "+My_Path);
        File myFile = new File(My_Path);

        int count;
       // byte[] buffer = new byte[8];

        //////////////////////////////////////////////

         try{
          
            //File myfile = new File("C:\\Users\\Me\\Pictures\\4qKtv.png");
           // OutputStream myOutStream = mySkt.getOutputStream();
            FileInputStream myFileIn = new FileInputStream(myFile);
            byte[] buffer = new byte[1024];
            int bytesRead = 0;
            int totalRead= 0;
            out_stream.writeObject("Take Your File...");
        out_stream.writeObject(receiver);
        out_stream.writeObject(file_path);
        out_stream.writeObject(myFile.length());

        
            while(myFileIn.available()>0)
            {
                bytesRead = myFileIn.read(buffer);
                out_stream.write(buffer);
                totalRead = totalRead + bytesRead;
                bytesRead =0;
                System.out.println(totalRead);
              out_stream.flush();
               //out_stream.reset();
            }
        System.out.println("Total sent "+totalRead);
           // myFileIn.close();

        }catch(IOException ex){
            ex.printStackTrace();
            System.out.println("Something went wrong.");
        }


        ///////////////////////////////////////////

    }




    //Method for sending file ends here




    //Method for receiving file starts...


    public static void receive_file(String file_name,String file_size_str)
    {
        String anotherPath = Base_Path+"\\"+file_name;
       

        System.out.println("Receiving file : " + file_name+" size: "+file_size_str);
       // byte[] buffer = new byte[8];
int count;
//InputStream in = socket.getInputStream();
try{

  
           int file_size = Integer.parseInt(file_size_str);
            File myFile = new File(anotherPath);

            if(!myFile.exists()){//check if file exists
                myFile.delete();
                myFile.createNewFile();
            }else{
                System.out.println("This File exists");
            }

            System.out.println("New file has been created!");
            FileOutputStream myFileOut = new FileOutputStream(myFile);
            //ObjectInputStream myInStream = in_stream;

             byte[] buffer = new byte[1024];

            int bytesReceived = 0;
            int totalReceived =0;

            System.out.println("available data "+in_stream.available());
            
            //in_stream.
            while(totalReceived<file_size) {
                bytesReceived = in_stream.read(buffer);
                if(bytesReceived>0)
                totalReceived = totalReceived + bytesReceived;
                if(totalReceived>file_size && bytesReceived>0 )
                {
                    //out.write(buffer, 0, file_size - (totalReceived - 1024));
                    myFileOut.write(buffer, 0, file_size - (totalReceived - 1024));
                    myFileOut.flush();
                }
                else{
                    //out.write(buffer,0,bytesReceived);
                    if(bytesReceived>0){
                    myFileOut.write(buffer,0,bytesReceived);
                    myFileOut.flush();}
                  //  if(in_stream.available()==0 && totalReceived<file_size)in_stream.wait(100);
           

                }
                System.out.println("$$ "+bytesReceived);



            }
            System.out.println(in_stream.available()+" total received "+totalReceived);
            myFileOut.close();

        }catch(Exception ex){
            ex.printStackTrace();
            System.out.println("Something went wrong");
        }finally{
            System.out.println("File Downloaded Successfully...");


    return;
}



            //////////////////////////////////////////



    } //Method for receiving file ends here...


public static class Handler extends Thread implements Runnable {


    public void Handler(){

    }
        @Override
     public void run()
    {
            boolean logged_in=true;

        try {

            while(logged_in){
              
            String rcv = in_stream.readObject().toString();

            if (rcv.equals("Shared_Files...")) {
                file_names_server = (ArrayList<String>) in_stream.readObject();
                //sample_Model_server.addElement(file_names_server);
                System.out.println("received " + file_names_server.size() + " files");
                sample_Model_server.clear();
                for (int i = 0; i < file_names_server.size(); i++) {
                    sample_Model_server.addElement(file_names_server.get(i));
                }
                jList_files_from_server.setModel(sample_Model_server);
            }
            else if(rcv.equals("Give me a file..."))
            {
                System.out.println("Download request from server received...");
                String file_to_send = in_stream.readObject().toString();
                String receiver = in_stream.readObject().toString();
                send_file(file_to_send,receiver);

            }
            else if(rcv.equals("Receive your file..."))
            {
                String received_file_name = in_stream.readObject().toString() ;
                String file_size_str = in_stream.readObject().toString();
                //int file_size = Integer.parseInt(in_stream.readObject().toString());
                receive_file(received_file_name,file_size_str);
            }
            else if(rcv.equals("GoodBye.."))
            {
                logged_in = false;
                System.out.println("I logged Out...");
            }
            }//while ends here....
        } catch (IOException ex) {
            Logger.getLogger(ClientHome.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(ClientHome.class.getName()).log(Level.SEVERE, null, ex);
        }

    }//run method ends here....
}//Handler class ends here....

/** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */

   

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jTabbedPane1 = new javax.swing.JTabbedPane();
        jPanel1 = new javax.swing.JPanel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jList1 = new javax.swing.JList();
        Share = new javax.swing.JButton();
        jPanel2 = new javax.swing.JPanel();
        jScrollPane2 = new javax.swing.JScrollPane();
        jList_files_from_server = new javax.swing.JList();
        jB_Download = new javax.swing.JButton();
        clientName = new javax.swing.JLabel();
        jBLogout = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setBounds(new java.awt.Rectangle(400, 150, 0, 0));

        jList1.setModel(new javax.swing.AbstractListModel() {
            String[] strings = { "Item 1", "Item 2", "Item 3", "Item 4", "Item 5" };
            public int getSize() { return strings.length; }
            public Object getElementAt(int i) { return strings[i]; }
        });
        jScrollPane1.setViewportView(jList1);

        Share.setText("Share");
        Share.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ShareActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 293, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(139, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addContainerGap(265, Short.MAX_VALUE)
                .addComponent(Share)
                .addGap(116, 116, 116))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(24, 24, 24)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 167, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(Share)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jTabbedPane1.addTab("Share", jPanel1);

        jList_files_from_server.setModel(new javax.swing.AbstractListModel() {
            String[] strings = { "Item 1", "Item 2", "Item 3", "Item 4", "Item 5" };
            public int getSize() { return strings.length; }
            public Object getElementAt(int i) { return strings[i]; }
        });
        jList_files_from_server.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        jScrollPane2.setViewportView(jList_files_from_server);

        jB_Download.setText("Download");
        jB_Download.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jB_DownloadActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(36, 36, 36)
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 274, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(132, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addContainerGap(338, Short.MAX_VALUE)
                .addComponent(jB_Download)
                .addGap(31, 31, 31))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(19, 19, 19)
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 178, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(34, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addContainerGap(197, Short.MAX_VALUE)
                .addComponent(jB_Download)
                .addContainerGap())
        );

        jTabbedPane1.addTab("All Files", jPanel2);

        clientName.setFont(new java.awt.Font("Times New Roman", 2, 18));
        clientName.setText("jLabel1");

        jBLogout.setText("Logout");
        jBLogout.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jBLogoutActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(252, 252, 252)
                .addComponent(clientName, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(195, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jTabbedPane1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 447, Short.MAX_VALUE)
                    .addComponent(jBLogout))
                .addGap(55, 55, 55))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(clientName, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jTabbedPane1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(31, 31, 31)
                .addComponent(jBLogout)
                .addContainerGap(41, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void ShareActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ShareActionPerformed
        // TODO add your handling code here:

        int[] indices = jList1.getSelectedIndices();
        //String[] sel = new String[indices.length];
        ArrayList<String> sel = new ArrayList<String>();
        for (int i = 0; i < indices.length; i++) {
           sel.add(jList1.getModel().getElementAt(indices[i]).toString() + "   $$$   "+ file_size_client.get(file_names_client.indexOf(jList1.getModel().getElementAt(indices[i]).toString())));

            System.out.println(" "+ i + ": "+ file_size_client.get(file_names_client.indexOf(jList1.getModel().getElementAt(indices[i]).toString())) +" name "+sel.get(i));

        }
        try {
            out_stream.writeObject("Sharable_Files");
            out_stream.writeObject(sel);
            //out_stream.writeObject("Ended...");

           /* String rcv = in_stream.readObject().toString();
            if(rcv.equals("Shared_Files...")){
            file_names_server = (ArrayList<String>)in_stream.readObject();
            //sample_Model_server.addElement(file_names_server);
            System.out.println("received "+file_names_server.size()+" files");
            sample_Model_server.clear();
            for(int i=0;i<file_names_server.size();i++)
            {
                sample_Model_server.addElement(file_names_server.get(i));
            }
            jList_files_from_server.setModel(sample_Model_server);
            }*/

        } catch (Exception ex) {
            Logger.getLogger(ClientHome.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_ShareActionPerformed

    private void jBLogoutActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jBLogoutActionPerformed
          
        try {
            out_stream.writeObject("GoodBye...");
           // out_stream.close();
           // in_stream.close();
        } catch (IOException ex) {
           // Logger.getLogger(ClientHome.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("Client Error...");
        }
        System.exit(0);
        
    }//GEN-LAST:event_jBLogoutActionPerformed

    private void jB_DownloadActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jB_DownloadActionPerformed
        // TODO add your handling code here:
        int index = jList_files_from_server.getSelectedIndex();
        String sels = jList_files_from_server.getModel().getElementAt(index).toString();
        System.out.println("file to download "+ sels);


       
        try {
           // in_stream.wait(100);
            out_stream.writeObject("Download for me...");
            out_stream.writeObject(sels);

        } catch (Exception ex) {
            Logger.getLogger(ClientHome.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jB_DownloadActionPerformed

    /**
    * @param args the command line arguments
    */
  /*
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ClientHome().setVisible(true);

                String path = ".";
                 String files;
  File folder = new File(path);
  File[] listOfFiles = folder.listFiles();
System.out.println("file number: "+listOfFiles.length);
  for (int i = 0; i < listOfFiles.length; i++)
  {

   if (listOfFiles[i].isFile())
   {
   files = listOfFiles[i].getName();
   System.out.println(files);
      }
  }
            }
        });
    }
*/
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Share;
    private javax.swing.JLabel clientName;
    private javax.swing.JButton jBLogout;
    private javax.swing.JButton jB_Download;
    private javax.swing.JList jList1;
    private static javax.swing.JList jList_files_from_server;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JTabbedPane jTabbedPane1;
    // End of variables declaration//GEN-END:variables

}
