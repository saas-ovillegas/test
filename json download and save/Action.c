Action()
{
	int i;			// 'for' counter
	char buff[50];	// string buffer for saving employee names
	char* filepath = "\employees.txt";
	
	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_start_transaction("File download transaction");

		web_add_header("X-P2P-PeerDist", 
			"Version=1.1");
	
		web_add_header("X-P2P-PeerDistEx", 
			"MinContentInformation=1.0, MaxContentInformation=2.0");
	
	// Capturing server response
		web_reg_save_param_ex(
			"ParamName=persons",
			"LB/IC=\"name\":\"",
			"RB=\", \"",
			"Ordinal=ALL",
			SEARCH_FILTERS,
			LAST);
	
		web_url("employees.json", 
			"URL=https://mybucket1a4s2d5.s3.amazonaws.com/employees.json", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=", 
			"Snapshot=t1.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("File download transaction",LR_AUTO);
	
	lr_start_transaction("Save to file transaction");
	
	for(i=1;i<4;i++)
	{
	//Saving each name entry per iteration
		sprintf(buff, "{persons_%d}", i);
		lr_save_string(lr_eval_string(buff),"p_persons");

	//Verification function, prints current value		
		//lr_output_message("Current value is: %s", lr_eval_string("{p_persons}"));
		
	//Save current entry to local file
		write_to_file(filepath, lr_eval_string("{p_persons}\n"));
	}
	
	lr_end_transaction("Save to file transaction",LR_AUTO);


	return 0;
}