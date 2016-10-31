
<div class="navbar">
    <div class="navbar-inner">
        <a class="brand" href="<?php echo site_url(); ?>"><img src="..img/new.png" alt="" class="img-circle pull-right"/>
		COOKBOOK 
		</a></br></br></br>
        <ul class="nav">

            
            <?php
           
            $is_logged_in_user = $this->session->userdata('is_logged_in_user');
			 $is_logged_in_admin = $this->session->userdata('is_logged_in_admin');

            if ((!isset($is_logged_in_admin) || $is_logged_in_admin != true) && (!isset($is_logged_in_user) || $is_logged_in_user != true)) {
                //NOT LOGGED  IN admin and user
            ?>
			
			    <li id="home_navbar"><a href="<?php echo site_url('welcome');?>">HOME</a></li> 
				<li id="archieve_navbar"><a href="<?php echo site_url('');?>">Archieve</a></li>
				<li id="contact_us_navbar"><a href="<?php echo site_url('contact_us');?>">Contact Us</a></li>
				<li id="archieve_navbar"><a href="<?php echo site_url('registration/registration_form');?>">Register</a></li>
                <li class="dropdown"  id="topics_navbar">
                     <a href="#" class="dropdown-toggle" data-toggle="dropdown">
                      LogIn
                      <b class="caret"></b>
                    </a>
                    <ul class="dropdown-menu">
                        <li><a tabindex="-1" href="<?php echo site_url('user_auth/login');?>">Already A Member</a></li>
                          <li class="divider"></li>
                          <li><a tabindex="-1" href="<?php echo site_url('registration/registration_form');?>">Registration</a></li>
                    </ul>

                </li>
				 


                
            <?php
            } else if((!isset($is_logged_in_admin) || $is_logged_in_admin != true) && (isset($is_logged_in_user) || $is_logged_in_user = true)) {
                //USER LOGGED IN
            ?>

             
                <li id="home_navbar"><a href="<?php echo site_url('Welcome');?>">HOME</a></li>
                <li id="profile_navbar"><a href="<?php echo site_url(''.$this->session->userdata('username'))?>">Profile</a></li>				
				<li id="archieve_navbar"><a href="<?php echo site_url('');?>">Archieve</a></li>
				<li id="events_navbar"><a href="<?php echo site_url('');?>">Events</a></li>
				<li class="dropdown"  id="topics_navbar">
                     <a href="#" class="dropdown-toggle" data-toggle="dropdown">
                      Discussion
                      <b class="caret"></b>
                    </a>
                    <ul class="dropdown-menu">
                        <li><a tabindex="-1" href="<?php echo site_url('');?>">Add Topics</a></li>
                          <li class="divider"></li>
                          <li><a tabindex="-1" href="<?php echo site_url('');?>">My Topics</a></li>
						   <li class="divider"></li>
                          <li><a tabindex="-1" href="<?php echo site_url('');?>">View Topics</a></li>
                    </ul>

                </li>
				
				<li id="settings_navbar"><a href="<?php echo site_url('');?>">Settings</a></li>
				<li id="logout_navbar"><a href="<?php echo site_url('user_auth/logout');?>"> Log Out!! </a></li>



            
			<?php
            } else if((isset($is_logged_in_admin) || $is_logged_in_admin = true) && (!isset($is_logged_in_user) || $is_logged_in_user != true)) {
                //ADMIN LOGGED IN
            ?>

             
                <li id="home_navbar"><a href="<?php echo site_url('welcome');?>">HOME</a></li>
                <li id="profile_navbar"><a href="<?php echo site_url('');?>">Add Archieve Image</a></li>
				 <li id="add_events_navbar"><a href="<?php echo site_url('');?>">Add events</a></li>
				
				<li id="archieve_navbar"><a href="<?php echo site_url('');?>">Archieve</a></li>
				
				<li id="member_navbar"><a href="<?php echo site_url('');?>">Change Password</a></li>
				
				<li id="logout_navbar"><a href="<?php echo site_url('admin_auth/logout');?>"> Log Out!! </a></li>



            <?php
            }
            ?>


        </ul>
    </div>
</div>


		