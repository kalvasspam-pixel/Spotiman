# FAQ

**What the hell is Spotiman?**

Spotiman is a device designed by two Czech students that were sick of modern music industry where listening to music feels like doomscrolling. We just wanted to hit play and enjoy.

**How does it work?**

It uses TFT screen that displays all the UI. It connects to your spotify account via Spotify API. You can import your playlist and listen with wired or bluetooth headphones. You can control Spotiman with rotary encoder. The heart of Spotiman creates ESP-32 WROOM. Your music will be saved on SD card so you can listen and manage it even if you are in the middle of Sahara. However only for now you need to use home server for downloading. But we are planning to also use an API for that.

**Wow, how did you design Spotiman?**

We used a couple of tools such as
- [Onshape](https://cad.onshape.com/documents/badc6da9251d2be217fd3a10/w/4c77092e45fc31b892930436/e/9490878c89b99a23a1bfab5c?renderMode=0&uiState=69919dd22cf206ae6cedbf38) for CAD
- [Lopaka](https://lopaka.app/gallery/28150/58584) for UI design
- Our own brains, AI and a lot of tutorials for firmware
- [Wokwi](https://wokwi.com/) for testing ideas.

**Spotiman is still in development. Feel free to contribute**

## Images

<img src="Images/Diagram_Principle_V2.png" width="200"> <img src="Images/Model_CAD_V1.png" width="400">

## TO DO:
- Edit the firmware so the esp doesn't crash when the encoder is rotated in wrong direction.
- Translate all notes in firmware to english.
- Create a scheme of Spotiman's menus.
- Design all Spotiman menus.
- Add all menus to Spotiman.
- Modify Spotiman's enclosure to fit the rotary encoder and eps32.
