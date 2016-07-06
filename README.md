# Digital Compass
A program that implements a digital compass using a LSM303D with a 
LPC1769 ARM Cortex-M3 form NXP.

## Getting Started

### Prequisites
1. LPCXpresso IDE
2. digital_compass source
3. LPC1769
4. LSM303D

#### Hardware Connections
```
 LPC1769           LSM303D
---------------------------------
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
1. Download digital_compass source
2. Run LPCXpresso and choose workspace location.
3. In the LPCXpresso quickstart panel (lower left corner), click on Import Projects.
3. In the import projects window click Browse under the Projected directory (unpacked). Browse for the digital_compass source you download in step 1 and click Next.
4. Select all (digital_compass, lpc_board_nxp_lpcxpresso_1769, lpc_chip_175x_6x). Under options check box for Copy projects into workspace. Click Finish.
5. Using the Quickstart panel, click on Build all projects.
6. Click the digital_compass folder in the Projects panel workspace (Upper left corner) to highlight it, if not already highlighted.
7. In the quickstart panel click Debug 'digital_compass'
8. Click on the resume button located on the top tool bar or press the F8 key. 
