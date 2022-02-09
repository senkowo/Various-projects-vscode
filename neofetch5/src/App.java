

import java.util.Scanner;




public class App {

	
			// Method that identifies the new appropriate directory-ID to update to (after cd command is used). 
	
    public static int dirManI(String input, int dirIC, int dirID, String directoryWhenIn) {
        input = input.replace("cd ", ""); 
        input = input.replace(" ", ""); 
        String loc1 = ""; 
	    String loc2 = ""; 
	    String loc3 = ""; 
	    String loc4 = ""; 
	    String loc5 = ""; 
	    
	    boolean escapeSplit = true;
	    
	    
    	

    	System.out.println(input);
	    
	    
	    
	    
	    
	    
	    while (escapeSplit == true) {
	    	
	    	
	    	String[] arrayDir = input.split("/"); 
        
	        for (int i=0; i<=arrayDir.length-1; i++) {
	            if (arrayDir[i] != null) {
	            }
	        }
	        int dirLength = arrayDir.length;
	        
	        if (dirLength >= 1) {
	            loc1 = (arrayDir[0]);
	            System.out.println(loc1); 
	        }
	        if (dirLength >= 2) {
	            loc2 = (arrayDir[1]);
	            System.out.println(loc2); 
	        }
	        if (dirLength >= 3) {
	            loc3 = (arrayDir[2]);
	            System.out.println(loc3); 
	        }
	        if (dirLength >= 4) {
	            loc4 = (arrayDir[3]);
	            System.out.println(loc4); 
	        }
	        if (dirLength >= 5) {
	            loc5 = (arrayDir[4]);
	            System.out.println(loc5); 
	        }
	        
	        if ((!input.contains("home")) && (dirID != 1)) {
	    		input = "home/"+ directoryWhenIn + "/" + loc1 + loc2 + loc3 + loc4 + loc5; //move this down there too? 
	    		input = input.replace("~", "home"); 
	    		
	        	escapeSplit = true;
	        } else {
	        	escapeSplit = false; 
	        }
        
    	}
        
	    
        boolean homeIn = false;
        if (loc1.equals("home")) {
        	dirIC = 1; 
        	homeIn = true;
        	
        	loc1 = loc2; loc2 = loc3; loc3 = loc4; 
        	
        	System.out.println("del later, home check");
        	System.out.println("del later, O"+loc1+"O");
        }
       	
       	
        
       	
       	System.out.println("fumofumo1");
       	System.out.println(loc1);        
       	switch(loc1) {
	       	case "Desktop":
	           	System.out.println("fumofumo2");
	            dirIC += 10; 
	            break; 
	                
	        case "Documents": 
	            dirIC += 20; 
	            break;
	                
	        case "Downloads": 
	        	dirIC += 30; 
	            break; 
	        case "Games": 
	          	dirIC += 40;
	                    
	            switch(loc2) {
	                case "Touhou6":
	                	dirIC += 100; 
	                	System.out.println("test: reached the touhou game");
	                	break; 
	                        
	            }
	            break;
	        case "Music": 
	        case "Pictures": 
	        case "Public": 
	        case "Tools":
	        case "Videos":
	           	break;
	            
	        
        }
        
    return dirIC;
    }


    
    		// Method that identifies the new directory name and system-directory name (when cd command is used). 
    
    public static String dirManN(int dirIC, boolean sysMode, boolean listMode) {
        String directoryO = ""; 
        String dirSysO = ""; 
        String list = "";
        String errorMessage = "error message, pls fix this.";
        
        switch(dirIC) {
            
            case 1:
                directoryO = "~"; 
                dirSysO = "/home/"; 
                list = "Desktop\nDocuments\nDownloads\nGames\nMusic\nPictures\nPublic\nTools\nVideos\n";
                break; 
        
        
            case 11: 
                directoryO = "Desktop"; 
                dirSysO = "/home/Desktop/"; 
                list = "";

                break; 
                
            case 21:
                directoryO = "Documents"; 
                dirSysO = "/home/Documents/";
                list = "";
                break; 
                
            case 31: 
            	directoryO = "Downloads"; 
            	dirSysO = "/home/Downloads/";
            	list = "";
            	break; 
            	
            case 41: 
            	directoryO = "Games"; 
            	dirSysO = "/home/Games/";
            	list = "Touhou6";
            	break; 
            case 141: 
            	directoryO = "Games/Touhou6"; 
            	dirSysO = "/home/Games/Touhou6/";
            	list = "Touhou6.exe";
            	break; 
                
                
        
        }
        
        
        
        if ((sysMode == false)&&(listMode == false)) {
        	return directoryO; 
        } else if ((sysMode == true)&&(listMode == false)) {
        	return dirSysO;
        } else if ((sysMode == false)&&(listMode == true)) {
        	return list; 
        } else {
        	return errorMessage;
        }
    }
        
        
    
    
    		// Method that lists all the folders/files in the directory. 
    
    		// Make it a static method instead, because only printing out? 
    
    

/* temp
    public static String dirMan(String input, String directoryC, String dirSysC, String Run) {
        input = input.replace("cd ", ""); 
        if (input.equals("/")) {
            dirSysC = "System";
            directoryC = "/"; 
        } else if ((input.equals("cd")) || (input.equals("~"))) {
            dirSysC = "home"; 
            directoryC = "~";
        } else {
            dirSys = "home" 
            
                //beginning, current home directory. 
            } if (dirSys.equals("home")) {
                if (input.contains("Downloads")) {
                    dirSysC = "home/Downloads"; 
                    directoryC = "Downloads"; 
                    if (((input.equals("Touhou6")) && (directory.equals("Downloads"))) || (input.equals("Downloads/Touhou6"))) {
                        dirSyscC = "home/Downloads/Touhou6"; 
                        directoryC = "Downloads/Touhou6"; 
                        if (((input.equals("Touhou06.exe")) && (directory.equals("Downloads/Touhou6"))) || (input.equals("Downloads/Touhou6/Touhou06.exe")))
                            Run = "Touhou06.exe"; 
                    }
                } if else (input.contains("Desktop")) {
                    dirSysC = "home/Downloads"; 
                    directoryC = "Desktop"; 
                    if (((input.equals("fumos")) && (directory.equals("Desktop"))) || (input.equals("Desktop/fumos"))) {
                        dirSysC = "home/Desktop/fumos"; 
                        directory = "Desktop/fumos"; 
                    }
                    
                }
            }
            
        }
        
        return dirSysC
    }
*/

    /*
    cd ("setInput()" + / + "setInput2()" + and pass trhough ..? 
    
    
    Another model: 
    cd home/case: Desktop
                case: 
            case: Documents
            case: Downloads
            
    for listing, if directory includes "directory," list these: ... 
    
    
    if cd /(list through:)          /   (keep inputting and sliding through and no need for a directory ID.) 
        (subtract "cd " from input, pass through and find matched pairs.)
            Desktop
            Downloads
            Documents
            (if land, add to another:)
            set numbers based on checked directories, return the number and into another method, which finds the dirctory. 
        directory += "/Documents"
        
    
            Scrap: 
            
    public static String dirMan(String input, String directoryC, ) {
        if (input.equals("/")) {
            dirSysC = "System";
            directoryC = "/"; 
        } else if ((input.equals("cd")) || (input.equals("~"))) {
            dirSys = "home"; 
            directory = "~""
        } else {
            dirSys = "System"; 
            if ((input.contains("kaia")) || (directory = )){
                dirSys += "/kaia"; 
                directory = "//kaia"; 
            }
        }
    }
    
    
    
    
    
    */
    
    public static void main(String[]args) {
        boolean breaker = false;
        boolean sysMode = false; 
        boolean listMode = false;
        String lsOut; 
        int dirID = 1; 
        String directory = "~";
        String dirSys = "/home/"; 
        int dirIC = 1; 
        boolean cdOverride = false; 
        String directoryWhenIn;
        
        Scanner sc = new Scanner(System.in); 
        System.out.println("Terminal (Arch) 1.0\n\n\"man\" for manual\n\"end\" or \"exit\" to close Terminal\n______________________________________");
        while(true){
            System.out.print("[kaia@chromebook "+directory+"]$ ");
            String input = sc.nextLine();
            if (input.equals("cd")) {
            	cdOverride = true; 
            }
            if ((input.contains("cd ")) || (cdOverride == true))  {
            	
            	directoryWhenIn = dirManN(dirIC, sysMode, listMode);
            	
            	
                dirIC = dirManI(input, dirIC, dirID, directoryWhenIn);
                if (cdOverride == true) {
                	dirIC = 1;
                	cdOverride = false;
                }
                System.out.println(dirIC); 
                directory = dirManN(dirIC, sysMode, listMode); // return directory (e.g. "~").
                System.out.println(directory);
                sysMode = true; 
                dirSys = dirManN(dirIC, sysMode, listMode); // return sys directory (e.g. "/home/").
                System.out.println(dirSys); 
                
                sysMode = false; 
                
                dirID = dirIC; 

            
            }
            if(input.equals("ls")) {
            	listMode = true;
            	lsOut = dirManN(dirIC, sysMode, listMode); 
            	listMode = false;
            	System.out.println(lsOut);

            }
            
            switch (input) {
                case "end":
                case "exit": 
                    System.out.println("exiting program");
                    breaker = true; 
                    break;
                case "man":
                case "manual": 
                    System.out.println("\nManual:\n----------\nA terminal based on Arch, even though Chrome OS is technically based on Gentoo.\nDebian-based commands will also work, however.\n");
                    System.out.println("Commands:\n------------\nneofetch\nnano\n");
                    System.out.println("sudo pacman -Syu\nsudo pacman -Syyu\nsudo -S APPLICATION\n\nsudo apt update\nsudo apt upgrade\nsudo apt update && sudo apt upgrade\nsudo apt-get update\nsudo apt-get upgrade\nsudo apt-get update && sudo apt-get upgrade\nsudo apt update && sudo apt-get upgrade\nsudo apt-get update && sudo apt upgrade\nsudo apt update && sudo apt dist-upgrade");
                    System.out.println("cd DIRECTORY\n~\ncd\n\\\nls\n ls -ln\n");
                    System.out.println("man\nmanual\n\nend\nexit\n");

                    //for these above, use a static method? since only print out lines? 
                    
                    break;
                case "neofetch": 

                    System.out.println("              `.-::////::-.`                  kaia@chromebook"); 
                    System.out.println("          `-/+oooooooooooooo+/-`              ---------------"); 
                    System.out.println("        ./oooooooooooooooooooooo/.            OS: Chrome OS x86_64"); 
                    System.out.println("      `/oooooooooooooooooooooooooo/`          Host: Dell Chromebook 3100"); 
                    System.out.println("     -`+oooooooooooooooooooooooooooo-         Kernel: 4.14.243-18084-g7bc10658733d"); 
                    System.out.println("    /s+`/oooooooo/:------------------`        Uptime: 3 hours, 34 mins"); 
                    System.out.println("   :sss+`:oooo+-`-/oooo/-`.:::::::::::.       Packages: 134 (crew)"); 
                    System.out.println("  `osssso.-oo/`:ssssssssss: -::::::::::       Shell: sh"); 
                    System.out.println("  -sssssso-.+`:ssssssssssss: ::::::::::.      Resolution: 1366 x 768"); 
                    System.out.println("  :ssssssss:` osssssssssssso -:::::::::.      Terminal: chrome"); 
                    System.out.println("  -sssssssss/ :ssssssssssss: ::::::::::.      CPU: Intel Celeron N4000 (4) @ 1.10GHz"); 
                    System.out.println("  `osssssssss+`:ssssssssss: -::::::::::       GPU: Intel Device 3185"); 
                    System.out.println("   :sssssssssso:`-/oooo/-``:::::::::::.       Memory:2278MiB / 3806MiB"); 
                    System.out.println("    /ssssssssssss+/:--::``:::::::::::-        ");
                    System.out.println("     :sssssssssssssssso..:::::::::::.         ██.██.██.██.██.██.██.██");
                    System.out.println("      .+ssssssssssssso`.::::::::::-`          ██.██.██.██.██.██.██.██");
                    System.out.println("        ./ssssssssss+`-:::::::::-`            ");
                    System.out.println("          `-/osssss/`-:::::::-.               ");
                    System.out.println("              `.-:- .---..`                   \n\n");
                    
                    break;
                case "fumo?":
                    System.out.println("fumo.");
                    break; 
                
                case "cd Downloads/":
                case "cd Downloads":
                    break;
                    
                    
                    
            }
        if (breaker==true) {
            break;
        }
        }
    }
}































