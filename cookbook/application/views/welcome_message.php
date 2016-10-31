<?php $this-> load->view('includes/header')?>

<script>
$(document).ready(

function()
{

<?php $data['selected_nav'] = "home_navbar";
$this-> load->view('includes/nav_helper',$data)?>

});
    </script>




<?php $this-> load->view('includes/navigation')?>

  <img border="0" src="<?php echo base_url().'/images/khulna.jpg'; ?>" >
  </br>
 <!-- <?php echo $this->google_maps->output();?> -->
		?>
  </br>
      This website has been created with a view to connecting all the BUET students hailed from KHULNA.
	  </br>
	  The group is supposed to be the platform to provide all the necessary informations about the KHULNAIAN recent and EX-students. 
	   </br>
	  So, guys, make this website active and feel free to ask any sort of questions after being registered.
	  </br>
      Guys be with this website and get all updates of upcoming activities arranged by GKABS as well as linked up with all KHULNA's brothers & sisters.
      Let's fly to our dream with brotherhood. 	  
	   </br>
	  Thanx to all for visiting this website.
	  </br>
<?php $this-> load->view('includes/footer')?>
