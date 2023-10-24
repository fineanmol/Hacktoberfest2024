package main
import (
	"fmt"
	"math"
)
type circle struct {
	radius float64
}
type square struct {
	side float64
}
type rectangle struct {
	length, width float64
}
func (c circle) area() float64 {
	return math.Pi * c.radius * c.radius
}
func (s square) area() float64 {
	return s.side * s.side
}
func (r rectangle) area() float64 {
	return r.length * r.width
}
type shape interface {
	area() float64
}
func info(s shape) {
	fmt.Println("Area:", s.area())
}
func main() {
	c := circle{radius: 5}
	s := square{side: 5}
	r := rectangle{length: 5, width: 10}
	info(c)
	info(s)
	info(r)
}
