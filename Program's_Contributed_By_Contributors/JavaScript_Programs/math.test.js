const { suma, multipli, divide } = require('./math.js');
//se requiere utilizar jest para comprabar funcinalidad de cualquier programa
test("Se coloca el mensaje como ejemplo adds 1 + 3 esperando como respueata 4", () => {
    const resulta = suma(1, 3);
    expect(resulta).toBe(4)
})

test("Testing de la funcion de multiplicar", () => {
    const resulta = multipli(8, 3);
    expect(resulta).toBe(24)
})

test("Testing de la funcion de dividir ", () => {
    const resulta = divide(10, 5);
    expect(resulta).toBe(2)
})

test("Funcion con error de testing", () => {
    const resulta = suma(3, 1);
    expect(resulta).toBe(6)
})

test("Testing de la funcion de dividir, varios escenarios", () => {
    const resultado1 = divide(10, 5);
    expect(resultado1).toBe(2)
    const resultado2 = divide(1, 4);
    expect(resultado2).toBe(0.25)
    const resultado3 = divide(9, 2);
    expect(resultado3).toBe(4.5)
    const resultadoNull = divide(10, 0);
    expect(resultadoNull).toBeNull();
})