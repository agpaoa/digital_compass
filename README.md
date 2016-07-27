# Digital Compass
A program that implements a digital compass using a LSM303D with a LPC1769 ARM Cortex-M3 from NXP. Displays heading, pitch, and roll data to the LPCXpresso console.

## Getting Started

### Prequisites
1. LPCXpresso IDE
2. digital_compass source
3. LPC1769
4. LSM303D

#### Hardware Connections
```
 LPC1769           LSM303D
---------------------------
 No connection     VDD
         H[28] --> VIN
 P0[0]   H[ 1] --> GND
 P0[1]   H[ 9] --> SDA
         H[10] --> SCL
 No connection     SDO
 No connection     INT1
 No Connection     INT2
```

### To Run
1. Download digital_compass source.
2. Run LPCXpresso and choose workspace location.
3. In the LPCXpresso Quickstart panel (lower left corner), click on **Import Projects**.
4. In the Import Projects Window
   - If the digital_compass source downloaded in step 1 is zipped, click **Browse** under **Project Archive (zip)** and browse for the zipped digital_compass source you downloaded in step 1.
   - If the digital_compass source downloaded in step 1 is not zipped, click **Browse** under **Project Directory (unpacked)** and browse for the digital_compass source you downloaded in step 1.
5. Click next after locating source.
6. Select all (digital_compass, lpc_board_nxp_lpcxpresso_1769, lpc_chip_175x_6x). Under Options check box for **Copy projects into workspace**. Click Finish.
7. Sometimes the LPCXpresso console will not handle a printf correctly with its default settings. To fix this go to the Quickstart panel and click on **Quick Settings**. Make sure all debug sessions are stopped and the digital_compass folder in the Projects panel workspace (Upper left corner) is highlighted.
   - Select **Set Library/Header Type**
   - Select **Newlib (semihost)**
8. Using the Quickstart panel, click on **Build all projects**.
9. Click the digital_compass folder in the Projects panel workspace (Upper left corner) to highlight it, if not already highlighted.
10. In the Quickstart panel click **Debug 'digital_compass'**.
11. Click on the resume button located on the top tool bar or press the **F8** key. 

### To Use
For this specific setup, the LSM303D chip is facing up. The x axis on the LSM303D is the direction of travel. To find North, point and move the direction of travel (the x axis) till the heading in the LPCXpresso console displays a reading of 0 or 359 degrees.
- Heading : rotate the compass about the z axis.
- Pitch   : rotate the compass about the y axis.
- Roll    : rotate the compass about the x axis. 