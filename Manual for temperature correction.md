## Manual for temperature correction

---

## 1) Fetching the data

- Use '501_temp_correction_template' to gather temperature values
- Use 'Saving the captured data in python' to save the data as csv and json files. Make sure the code runs until the temperature is roughly constant
- As you finish the data capture in python, take a measurement of the temperature using a digital thermometer.

---

## 2) Processing the data

- Repeat multiple times, then use 'graph for temperature correction'. Insert the necessary values in matching order (Treal1,Treal2 then Tarduino1, Tarduino2), separated by commas. 
- The graph of Treal vs Tarduino will be plotted. Write down the c and k values.

---

## 3) Finish
- You are done! You can now use those values in the Arduino data collection code. To see the difference between the calibrated and non-calibrated values, use '501_temp_correction_template' to observe how the measured and corrected values differ in real time.
