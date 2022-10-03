package main

import (
	"image/png"
	"os"
	"image"
	"io/ioutil"
	"bytes"
	"fmt"

	"github.com/liyue201/goqr"
	"github.com/boombuler/barcode"
	"github.com/boombuler/barcode/qr"
)


func qrCodeGen(t string, filename string) (error) {

	qrCode, _ := qr.Encode(t, qr.M, qr.Auto)
	qrCode, _ = barcode.Scale(qrCode, 2000, 2000)

	file, err := os.Create(filename)
	defer file.Close()

	png.Encode(file, qrCode)
	return err
}

func scanQRCode(path string) {

	imgdata, err := ioutil.ReadFile(path)
	if err != nil {
		fmt.Printf("%v\n", err)
		return
	}

	img, _, err := image.Decode(bytes.NewReader(imgdata))
	if err != nil {
		fmt.Printf("image.Decode error: %v\n", err)
		return
	}

	qrCodes, err := goqr.Recognize(img)
	if err != nil {
		fmt.Printf("Recognize failed: %v\n", err)
		return
	}
	
	for _, qrCode := range qrCodes {
		fmt.Printf("qrCode text: %s\n", qrCode.Payload)
	}
	return
}

func main() {

	t := "This is a text"
	filenameR := "qrcode.png"
	qrCodeGen(t, filenameR)

	filenameW := "qrcode.png"
	scanQRCode(filenameW)

}
