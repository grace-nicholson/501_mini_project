# 501_mini_project

# Investigating the change of bathroom conditions during the daily use with Nicla Sense ME and Arduino MKR WiFi 1010

This project is focused on gathering environmental data from a studio bathroom, using a nicla sense ME and Arduino MKR WiFi 1010, with the data fetched using Arduino IDE and Python code.

---

## Overview

This repository contains code for collecting, processing, and analysing environmental data captured by the Nicla Sense ME sensor.  
The goal of the project is to investigate how bathroom conditions change during the use of different appliances and products.

In the experiment, the measured variables include temperature, humidity, and air quality under the influence of activities such as shower use, toilet cleaning products, and air fresheners. These variables can be easily modified to suit other environmental investigations.

This project is intended for students as an example of how sensors and microcontrollers can be used to study environmental changes, as well as for researchers who wish to conduct similar measurements.

---

## Features

- Wireless data acquisition using Arduino IDE and Nicla Sense ME
- Collection of temperature, humidity, and air quality measurements
- Python-based data storage in JSON and CSV formats, including metadata
- Optional integration of external weather data via a weather API
- Data cleaning and anomaly removal
- Storage of processed data in individual and combined SQL databases
- Simple, customizable query system for extracting specific datasets
- Visualization of time-dependent environmental changes through plotted graphs
- Temperature calibration workflow using reference thermometer measurements

---

## Installation

1. Install the Arduino IDE and required board libraries.
2. Install Python dependencies listed in `Requirements`.
3. Configure WiFi credentials, API keys and file-paths where required.


## Authors

- Grace Nicholson 
- MSc in Digital Chemistry student, University of Liverpool
- GitHub: https://github.com/grace-nicholson

---

- Franciszek Daniewski 
- MSc in Digital Chemistry student, University of Liverpool
- GitHub: https://github.com/sgfdanie

## Acknowledgements
- We would like to thank Dr. Joe Forth for academic guidance during the span of this project.
- Github: https://github.com/joeforth

