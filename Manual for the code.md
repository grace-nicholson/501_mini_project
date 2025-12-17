## Manual for the main code

---

## 1) Fetching the data
- Use `501_arduino_code` in main or `Template of fetching data with temperature correction` in Temperature-calibration branch to fetch the data from Arduino. The latter file allows you to use the calibrated temperature values (Manual on how to compute them is also present in the Temperature-calibration branch). When fetching the data using WiFi, remember to update the credentials and use a cable connection at first.

- Once the credentials are updated, open serial monitor and wait for a message confirming your connection. Wait 30s until the first results fetch. This means your code has been uploaded successfully. You can then unplug your Arduino, plug it to an external power source and continue with the python code.
  
- Use `project_python_code` to  capture the data into json and csv files. Read the `requirements` document to learn how to receive your unique API key to enable Weather API metadata fetching. The resulting files will be saved in the same location as the python code. 

---

## 2) Data processing
- Use `code for graphs` in main to visualise your data and hence determine whether data sets are usable. If outliers and anomalous data are present you can either use the code contained in the graph making program to take the outliers out, or completely clean your data set using `SQL and cleanup code final`, also found in the main branch. The cleaning code for both csv and json files is right on the top. so if you do not want to make SQL databases, you can ignore the rest of the code.
  
- If you do choose to form SQL databases, using the code mentioned above you can:
1. Create a database for each experiment independently 
2. Merge different databases
3. Fetch specific queries, and test functionality of your databases

- It is important to note that the database code uses csv files and locates them using pathways. As you will have to enter the paths manually and alter between them quite often to compile multiple databases together, make sure to save the files in convenient places. 

