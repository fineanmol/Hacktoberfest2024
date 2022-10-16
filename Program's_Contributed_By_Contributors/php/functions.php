<?php
//Funções Gerais de Utilização para o Brasil
function nome_abreviado($nome)
{
 //Retorna um nome pessoal abreviado. Apenas primeiro e último nomes completos.
 $nome_array = explode(' ', trim(titulo($nome)));
 if (sizeof($nome_array) > 1) {
  $nome_abreviado = $nome_array[0];
  for ($x = 1; $x <= sizeof($nome_array) - 2; $x++) {
   if ($nome_array[$x] != 'Do' and $nome_array[$x] != 'Da' and $nome_array[$x] != 'Dos' and $nome_array[$x] != 'Das') {
    $nome_abreviado = $nome_abreviado . ' ' . substr($nome_array[$x], 0, 1);
   }
  }
  $nome_abreviado = $nome_abreviado . ' ' . $nome_array[sizeof($nome_array) - 1];
  return $nome_abreviado;
 } else {
  return titulo($nome);
 }
}

function dois_primeiros_nomes($nome)
{
 $nome_array = explode(' ', trim(titulo($nome)));
 //Retorna um nome pessoal abreviado. Apenas primeiro e último nomes completos.    $nome_array = explode(' ', trim($nome));
 if (sizeof($nome_array) > 1) {
  $nome_abreviado = $nome_array[0] . ' ' . $nome_array[1];
  return $nome_abreviado;
 } else {
  return $nome;
 }
}

function primeiro_nome($nome)
{
 //Retorna um nome pessoal abreviado. Apenas primeiro e último nomes completos.
 $nome_array = explode(' ', trim($nome));
 if (sizeof($nome_array) > 1) {
  $nome_abreviado = $nome_array[0];
  return $nome_abreviado;
 } else {
  return $nome;
 }
}

function todas_maiusculas($string)
{
 //Retorna String com todas as letras maiúsculas.
 return mb_strtoupper($string, 'UTF-8');
}

function todas_minusculas($string)
{
 //Retorna String com todas as letras minúsculas.
 return mb_strtolower($string, 'UTF-8');
}

function titulo($string)
{
 //Retorna texto no padrão de título, com primeiras letras em maisculo, excetuando preposições e artigos.
 $string = mb_convert_case($string, MB_CASE_TITLE, "UTF-8");
 $retorno = "";
 $palavras = explode(' ', $string);
 $cont = 0;
 foreach ($palavras as $palavra) {
  $cont++;
  if ($cont > 1 and ($palavra == 'Do' or
   $palavra == 'Dos' or
   $palavra == 'Da' or
   $palavra == 'Das' or
   $palavra == 'De' or
   $palavra == 'No' or
   $palavra == 'Nos' or
   $palavra == 'Na' or
   $palavra == 'Nas' or
   $palavra == 'O' or
   $palavra == 'A' or
   $palavra == 'Os' or
   $palavra == 'As' or
   $palavra == 'À' or
   $palavra == 'Ao' or
   $palavra == 'Às' or
   $palavra == 'E' or
   $palavra == 'É' or
   $palavra == 'Que' or
   $palavra == 'Pra' or
   $palavra == 'Para' or
   $palavra == 'Em' or
   $palavra == 'Um' or
   $palavra == 'Uma' or
   $palavra == 'Uns' or
   $palavra == 'Umas')) {
   $palavra = mb_strtolower($palavra, 'UTF-8');
  }
  $retorno = $retorno . ' ' . $palavra;
 }
 return $retorno;
}

function so_numeros($str)
{
 //Retorna apenas os números de uma string
 return preg_replace("/[^0-9]/", "", $str);
}

function remover_acentos($var)
{
 $var = preg_replace("[ÁÀÂÃ]", "A", $var);
 $var = preg_replace("[áàâãª]", "a", $var);
 $var = preg_replace("[ÉÈÊ]", "E", $var);
 $var = preg_replace("[éèê]", "e", $var);
 $var = preg_replace("[ÓÒÔÕ]", "O", $var);
 $var = preg_replace("[óòôõº]", "o", $var);
 $var = preg_replace("[ÚÙÛ]", "U", $var);
 $var = preg_replace("[úùû]", "u", $var);
 $var = str_replace("Ç", "C", $var);
 $var = str_replace("ç", "c", $var);
 return trim($var);
}

function valida_cnpj($cnpj)
{ //retorna true para CNPJ VÁLIDO
 // Deixa o CNPJ com apenas números
 $cnpj = preg_replace('/[^0-9]/', '', $cnpj);
 // Garante que o CNPJ é uma string
 $cnpj = (string) $cnpj;
 // O valor original
 $cnpj_original = $cnpj;
 // Captura os primeiros 12 números do CNPJ
 $primeiros_numeros_cnpj = substr($cnpj, 0, 12);
 /**
  * Multiplicação do CNPJ
  *
  * @param string $cnpj Os digitos do CNPJ
  * @param int $posicoes A posição que vai iniciar a regressão
  * @return int O
  *
  */
 if (!function_exists('multiplica_cnpj')) {
  function multiplica_cnpj($cnpj, $posicao = 5)
  {
   // Variável para o cálculo
   $calculo = 0;
   // Laço para percorrer os item do cnpj
   for ($i = 0; $i < strlen($cnpj); $i++) {
    // Cálculo mais posição do CNPJ * a posição
    $calculo = $calculo + ($cnpj[$i] * $posicao);
    // Decrementa a posição a cada volta do laço
    $posicao--;
    // Se a posição for menor que 2, ela se torna 9
    if ($posicao < 2) {
     $posicao = 9;
    }
   }
   // Retorna o cálculo
   return $calculo;
  }
 }
 // Faz o primeiro cálculo
 $primeiro_calculo = multiplica_cnpj($primeiros_numeros_cnpj);
 // Se o resto da divisão entre o primeiro cálculo e 11 for menor que 2, o primeiro
 // Dígito é zero (0), caso contrário é 11 - o resto da divisão entre o cálculo e 11
 $primeiro_digito = ($primeiro_calculo % 11) < 2 ? 0 : 11 - ($primeiro_calculo % 11);
 // Concatena o primeiro dígito nos 12 primeiros números do CNPJ
 // Agora temos 13 números aqui
 $primeiros_numeros_cnpj .= $primeiro_digito;
 // O segundo cálculo é a mesma coisa do primeiro, porém, começa na posição 6
 $segundo_calculo = multiplica_cnpj($primeiros_numeros_cnpj, 6);
 $segundo_digito = ($segundo_calculo % 11) < 2 ? 0 : 11 - ($segundo_calculo % 11);
 // Concatena o segundo dígito ao CNPJ
 $cnpj = $primeiros_numeros_cnpj . $segundo_digito;
 // Verifica se o CNPJ gerado é idêntico ao enviado
 if ($cnpj === $cnpj_original) {
  return true;
 }
}

function valida_cpf($cpf)
{
 /**
  * Multiplica dígitos vezes posições 
  *
  * @param string $digitos Os digitos desejados
  * @param int $posicoes A posição que vai iniciar a regressão
  * @param int $soma_digitos A soma das multiplicações entre posições e dígitos
  * @return int Os dígitos enviados concatenados com o último dígito
  */
 if (!function_exists('calc_digitos_posicoes')) {
  function calc_digitos_posicoes($digitos, $posicoes = 10, $soma_digitos = 0)
  {
   // Faz a soma dos dígitos com a posição
   // Ex. para 10 posições: 
   //   0    2    5    4    6    2    8    8   4
   // x10   x9   x8   x7   x6   x5   x4   x3  x2
   //   0 + 18 + 40 + 28 + 36 + 10 + 32 + 24 + 8 = 196
   for ($i = 0; $i < strlen($digitos); $i++) {
    $soma_digitos = $soma_digitos + ($digitos[$i] * $posicoes);
    $posicoes--;
   }
   // Captura o resto da divisão entre $soma_digitos dividido por 11
   // Ex.: 196 % 11 = 9
   $soma_digitos = $soma_digitos % 11;
   // Verifica se $soma_digitos é menor que 2
   if ($soma_digitos < 2) {
    // $soma_digitos agora será zero
    $soma_digitos = 0;
   } else {
    // Se for maior que 2, o resultado é 11 menos $soma_digitos
    // Ex.: 11 - 9 = 2
    // Nosso dígito procurado é 2
    $soma_digitos = 11 - $soma_digitos;
   }
   // Concatena mais um dígito aos primeiro nove dígitos
   // Ex.: 025462884 + 2 = 0254628842
   $cpf = $digitos . $soma_digitos;
   // Retorna
   return $cpf;
  }
 }
 // Verifica se o CPF foi enviado
 if (!$cpf) {
  return false;
 }
 // Remove tudo que não é número do CPF
 // Ex.: 025.462.884-23 = 02546288423
 $cpf = preg_replace('/[^0-9]/is', '', $cpf);
 //Verifica se não há numeros repetidos
 if (
  $cpf == '00000000000' ||
  $cpf == '11111111111' ||
  $cpf == '22222222222' ||
  $cpf == '33333333333' ||
  $cpf == '44444444444' ||
  $cpf == '55555555555' ||
  $cpf == '66666666666' ||
  $cpf == '77777777777' ||
  $cpf == '88888888888' ||
  $cpf == '99999999999'
 ) {
  return false;
 }
 // Verifica se o CPF tem 11 caracteres
 // Ex.: 02546288423 = 11 números
 if (strlen($cpf) != 11) {
  return false;
 }
 // Captura os 9 primeiros dígitos do CPF
 // Ex.: 02546288423 = 025462884
 $digitos = substr($cpf, 0, 9);
 // Faz o cálculo dos 9 primeiros dígitos do CPF para obter o primeiro dígito
 $novo_cpf = calc_digitos_posicoes($digitos);
 // Faz o cálculo dos 10 dígitos do CPF para obter o último dígito
 $novo_cpf = calc_digitos_posicoes($novo_cpf, 11);
 // Verifica se o novo CPF gerado é idêntico ao CPF enviado
 if ($novo_cpf === $cpf) {
  // CPF válido
  return true;
 } else {
  // CPF inválido
  return false;
 }
}

function formata_cnpj_cpf($cnpj_cpf)
{
 // O valor formatado
 $formatado = so_numeros($cnpj_cpf);
 // Valida CPF
 if (strlen($formatado) == 11) {
  // Formata o CPF ###.###.###-##
  $formatado = substr($cnpj_cpf, 0, 3) . '.';
  $formatado .= substr($cnpj_cpf, 3, 3) . '.';
  $formatado .= substr($cnpj_cpf, 6, 3) . '-';
  $formatado .= substr($cnpj_cpf, 9, 2) . '';
  // Valida CNPJ
 } else {
  // Formata o CNPJ ##.###.###/####-##
  if (strlen($formatado) == 14) {
   $formatado = substr($cnpj_cpf, 0, 2) . '.';
   $formatado .= substr($cnpj_cpf, 2, 3) . '.';
   $formatado .= substr($cnpj_cpf, 5, 3) . '/';
   $formatado .= substr($cnpj_cpf, 8, 4) . '-';
   $formatado .= substr($cnpj_cpf, 12, 14) . '';
  }
 }
 // Retorna o valor 
 return $formatado;
}

//Funções abaixo são para DataHora
//Função abaixo converte data brasileira para o padrão MySQL
function convert_data_para_bd($data)
{
 $data = implode('-', array_reverse(explode('/', $data)));
 return $data;
}

//Função abaixo converte data MySQL para o padrão Brasileiro
function convert_data_para_br($data)
{
 $data = implode('/', array_reverse(explode('-', $data)));
 return $data;
}

//Função abaixo pega data e hora no padrão brasileiro e gera o timestamp
function pegar_timestamp($data_br, $hora_br)
{
 $data_array = explode('/', $data_br);
 $dia = intval($data_array[0]);
 $mes = intval($data_array[1]);
 $ano = intval($data_array[2]);
 $hora_array = explode(':', $hora_br);
 $hora = intval($hora_array[0]);
 $minuto = intval($hora_array[1]);
 $segundo = intval($hora_array[2]);
 return mktime($hora, $minuto, $segundo, $mes, $dia, $ano);
}

//Função abaixo pega o timestamp e gera data e hora no padrão brasileiro
function convert_time_datahora($timestamp)
{
 if ($timestamp != 0) {
  return date('d/m/Y H:i', $timestamp);
 } else {
  return '-';
 }
}

//Função abaixo converte o timestamp apenas para a Hora definida
function convert_time_hora($timestamp)
{
 if ($timestamp != 0) {
  return date('H:i', $timestamp);
 } else {
  return '-';
 }
}

//Função abaixo converte timestap apenas para a data definida
function convert_time_data($timestamp)
{
 if ($timestamp != 0) {
  return date('d/m/Y', $timestamp);
 } else {
  return;
 }
}

function convert_time_us_data($timestamp)
{
 if ($timestamp != 0) {
  return date('m/d/Y', $timestamp);
 } else {
  return '-';
 }
}

//Retorna hora atual no formato HH:MM
function hora_atual()
{
 $today = time();
 $horaatual = date('H:i', $today);
 return ($horaatual);
}

//Retorna o dia atual com 2 díditos()
function dia_atual()
{
 $today = time();
 $diaatual = date('d', $today);
 return ($diaatual);
}

function dia_atual_sem_zero()
{
 $today = time();
 $diaatual = date('j', $today);
 return ($diaatual);
}

//Retorna o mês atual com 2 digitos(MM)
function mes_atual()
{
 $today = time();
 $mesatual = date('m', $today);
 return ($mesatual);
}

//Retorna o mês atual sem zero antes(1,5,10,12,etc)
function mes_atual_sem_zero()
{
 $today = time();
 $mesatual = date('n', $today);
 return ($mesatual);
}

//Retorna o ano atual com 4 digitos(AAAA)
function ano_atual()
{
 $today = time();
 $anoatual = date('Y', $today);
 return ($anoatual);
}

//Retorna a data atual no formato(DD/MM/AAAA)
function data_atual()
{
 $today = time();
 $dataatual = date('d/m/Y', $today);
 return ($dataatual);
}

//Retorna o valor da data no formato(DD/MM/AAAA)
function somar_horas_a_hoje($valor)
{
 $today = time() + ($valor * 60 * 60);
 $retorno = date('d/m/Y', $today);
 return ($retorno);
}

//Retorna o valor da data no formato(DD/MM/AAAA)
function somar_dias_a_hoje($valor)
{
 $time = time() + ($valor * 24 * 60 * 60);
 $retorno = date('d/m/Y', $time);
 return ($retorno);
}

function total_dias_mes($mes, $ano)
{
 $totalDeDiasMes = date("t", mktime(10, 10, 10, $mes, 1, $ano));
 return $totalDeDiasMes;
}

///Ao enviar o mes como parâmetro na função abaixo, enviar com dois dígitos para não haver erros
function mes_eh_antigo($mes, $ano)
{
 $today = time();
 $dataAtual = date('Ym', $today);
 $dataLimite = $ano . $mes;
 if ($dataAtual > $dataLimite) {
  return true;
 } else {
  return false;
 }
}

// SOMAR DATAS timestamp 
// SUBTRAIR DATAS timestamp 
function subtrair_datas_timestamp($d1, $d2)
{
 // verifica a diferença em segundos entre as duas datas e divide pelo número de segundos que um dia possui
 $dataFinal = ($d2 - $d1) / 86400;
 // caso a data 2 seja menor que a data 1
 if ($dataFinal < 0)
  $dataFinal = $dataFinal * -1;
 return $dataFinal;
}

function subtrair_datas($d1, $d2)
{
 $data1 = $d1; //"25/02/2013";
 $data2 = $d2; //"22/02/2013";
 // converte as datas para o formato timestamp
 $dt1 = strtotime($data1);
 $dt2 = strtotime($data2);
 // verifica a diferença em segundos entre as duas datas e divide pelo número de segundos que um dia possui
 $dataFinal = ($dt2 - $dt1) / 86400;
 // caso a data 2 seja menor que a data 1
 if ($dataFinal < 0)
  $dataFinal = $dataFinal * -1;
 return $dataFinal;
}

//Retorna o nome do mês se for enviado o respectivo número como parâmetro.
function numero_para_mes($valor)
{
 switch ($valor) {
  case 1:
   $retorno = 'Janeiro';
   break;
  case 2:
   $retorno = 'Fevereiro';
   break;
  case 3:
   $retorno = 'Março';
   break;
  case 4:
   $retorno = 'Abril';
   break;
  case 5:
   $retorno = 'Maio';
   break;
  case 6:
   $retorno = 'Junho';
   break;
  case 7:
   $retorno = 'Julho';
   break;
  case 8:
   $retorno = 'Agosto';
   break;
  case 9:
   $retorno = 'Setembro';
   break;
  case 10:
   $retorno = 'Outubro';
   break;
  case 11:
   $retorno = 'Novembro';
   break;
  case 12:
   $retorno = 'Dezembro';
   break;
  case "01":
   $retorno = 'Janeiro';
   break;
  case "02":
   $retorno = 'Fevereiro';
   break;
  case "03":
   $retorno = 'Março';
   break;
  case "04":
   $retorno = 'Abril';
   break;
  case "05":
   $retorno = 'Maio';
   break;
  case "06":
   $retorno = 'Junho';
   break;
  case "07":
   $retorno = 'Julho';
   break;
  case "08":
   $retorno = 'Agosto';
   break;
  case "09":
   $retorno = 'Setembro';
   break;
  case "10":
   $retorno = 'Outubro';
   break;
  case "11":
   $retorno = 'Novembro';
   break;
  case "12":
   $retorno = 'Dezembro';
   break;
 }
 return ($retorno);
}

//Função abaixo pega horario de início e término em HH:MM e calcula a duração do turno
function calcular_duracao_turno($inicio, $fim)
{
 if ($inicio != '' and $fim != '') {
  //Função que calcula o tempo de serviço de um turno. Inicio e fim devem vir no formato HH:MM.//CONTINUAR
  $tempoEmMinutos = 0;
  $inicioArray = explode(':', trim($inicio));
  $fimArray = explode(':', trim($fim));
  $horaIni = $inicioArray[0] * 60 + $inicioArray[1]; //Da a quantidade de minutos a partir das 00h   
  $horaFim = $fimArray[0] * 60 + $fimArray[1]; //Da a quantidade de minutos a partir das 00h
  //echo ' HoraIni:'.$horaIni.' HoraFim:'.$horaFim;
  if ($horaIni < $horaFim) {
   //    echo ' IF1 ';
   $tempoEmMinutos = $horaFim - $horaIni;
  } elseif ($horaIni > $horaFim) {
   //    echo ' IF2 ';
   $tempoEmMinutos = $horaFim + (24 * 60 - $horaIni);
  } elseif ($horaIni == $horaFim) {
   //    echo ' IF3 ';
   $tempoEmMinutos = 24 * 60;
  }
  //echo ' Tempo em minutos do turno:'.$tempoEmMinutos;
  return $tempoEmMinutos;
 }
}

//Funções para email e segurança//
function validar_email_real($email)
{
 //Verifica se o email é real, se tem um DNS ativo.
 if (filter_var($email, FILTER_VALIDATE_EMAIL)) {
  //Valida o dominio
  $dominio = explode('@', $email);
  if (!checkdnsrr($dominio[1], 'A')) {
   return false;
  } else {
   return true;
  }
 } else {
  return false;
 }
}

function capturar_ip()
{
 //Captura o IP do usuário
 if (!empty($_SERVER['HTTP_CLIENT_IP'])) {
  $ip = $_SERVER['HTTP_CLIENT_IP'];
 } elseif (!empty($_SERVER['HTTP_X_FORWARDED_FOR'])) {
  $ip = $_SERVER['HTTP_X_FORWARDED_FOR'];
 } else {
  $ip = $_SERVER['REMOTE_ADDR'];
 }
 return $ip;
}

function slug($str)
{
 $comAcentos = array('à', 'á', 'â', 'ã', 'ä', 'å', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', 'ù', 'ü', 'ú', 'ÿ', 'À', 'Á', 'Â', 'Ã', 'Ä', 'Å', 'Ç', 'È', 'É', 'Ê', 'Ë', 'Ì', 'Í', 'Î', 'Ï', 'Ñ', 'Ò', 'Ó', 'Ô', 'Õ', 'Ö', 'O', 'Ù', 'Ü', 'Ú');
 $semAcentos = array('a', 'a', 'a', 'a', 'a', 'a', 'c', 'e', 'e', 'e', 'e', 'i', 'i', 'i', 'i', 'n', 'o', 'o', 'o', 'o', 'o', 'u', 'u', 'u', 'y', 'A', 'A', 'A', 'A', 'A', 'A', 'C', 'E', 'E', 'E', 'E', 'I', 'I', 'I', 'I', 'N', 'O', 'O', 'O', 'O', 'O', '0', 'U', 'U', 'U');

 $str = strtolower($str);
 $str = str_replace($comAcentos, $semAcentos, $str);
 $str = str_replace('.', '-', $str);
 $str = str_replace(',', '-', $str);
 $str = str_replace('´', '-', $str);
 $str = str_replace(' ', '-', $str);

 return $str;
}

function gerarSlug($str)
{
 $str = mb_strtolower($str); //Vai converter todas as letras maiúsculas pra minúsculas
 $str = preg_replace('/(â|á|ã)/', 'a', $str);
 $str = preg_replace('/(ê|é)/', 'e', $str);
 $str = preg_replace('/(í|Í)/', 'i', $str);
 $str = preg_replace('/(ú)/', 'u', $str);
 $str = preg_replace('/(ó|ô|õ|Ô)/', 'o', $str);
 $str = preg_replace('/(_|\/|!|\?|#)/', '', $str);
 $str = preg_replace('/( )/', '-', $str);
 $str = preg_replace('/ç/', 'c', $str);
 $str = preg_replace('/(-[-]{1,})/', '-', $str);
 $str = preg_replace('/(,)/', '-', $str);

 $str = strtolower($str);
 return $str;
 /*Significa que vai procurar por  qualquer um desses â|á|ã ou as outras 
    letras e, i, o, u e caracteres especiais e vai trocar pela letra normal ou pelo -*/
}

function slugify($text, string $divider = '-')
{
 // replace non letter or digits by divider
 $text = preg_replace('~[^\pL\d]+~u', $divider, $text);

 // transliterate
 $text = iconv('utf-8', 'us-ascii//TRANSLIT', $text);

 // remove unwanted characters
 $text = preg_replace('~[^-\w]+~', '', $text);

 // trim
 $text = trim($text, $divider);

 // remove duplicate divider
 $text = preg_replace('~-+~', $divider, $text);

 // lowercase
 $text = strtolower($text);

 if (empty($text)) {
  return 'n-a';
 }

 return $text;
}

// formats money to a whole number or with 2 decimals; includes a dollar sign in front
function formatMoney($real_number, $cents = 2)
{ // cents: 0=never, 1=if needed, 2=always
 if (is_null($real_number)) {
  return 'R$0,00';
 } else {
  $number = $real_number / 100;
  if (is_numeric($number)) { // a number
   if (!$number) { // zero
    $money = ($cents == 2 ? '0.00' : '0'); // output zero
   } else { // value
    if (floor($number) == $number) { // whole number
     $money = number_format($number, ($cents == 2 ? 2 : 0), ',', '.'); // format
    } else { // cents
     $money = number_format(round($number, 2), ($cents == 0 ? 0 : 2), ',', '.'); // format
    } // integer or decimal
   } // value
   if ($money >= 0) {
    return 'R$' . $money;
   } else {
    $money = explode('-', $money);
    return '-R$' . $money[1];
   }
  } // numeric
 } // formatMoney
}

// formats money to a whole number or with 2 decimals; includes a dollar sign in front
function formatMoneyWithoutSign($real_number, $cents = 2)
{ // cents: 0=never, 1=if needed, 2=always
 $number = $real_number / 100;
 if (is_numeric($number)) { // a number
  if (!$number) { // zero
   $money = ($cents == 2 ? '0.00' : '0'); // output zero
  } else { // value
   if (floor($number) == $number) { // whole number
    $money = number_format($number, ($cents == 2 ? 2 : 0), ',', '.'); // format
   } else { // cents
    $money = number_format(round($number, 2), ($cents == 0 ? 0 : 2), ',', '.'); // format
   } // integer or decimal
  } // value
  return $money;
 } // numeric
} // formatMoney

// formats percentage to a whole number or with 2 decimals; includes a dollar sign in front
function formatPercentage($real_number, $cents = 2)
{ // cents: 0=never, 1=if needed, 2=always
 $number = $real_number / 100;
 if (is_numeric($number)) { // a number
  if (!$number) { // zero
   $percentage = ($cents == 2 ? '0.00' : '0'); // output zero
  } else { // value
   if (floor($number) == $number) { // whole number
    $percentage = number_format($number, ($cents == 2 ? 2 : 0)); // format
   } else { // cents
    $percentage = number_format(round($number, 2), ($cents == 0 ? 0 : 2)); // format
   } // integer or decimal
  } // value
  return $percentage . ' %';
 } // numeric
} // formatMoney

function phoneFormat($numero)
{
 $real_number = so_numeros($numero);
 $tam = strlen($real_number);
 if ($tam == 13) { // COM CÓDIGO DE ÁREA NACIONAL E DO PAIS e 9 dígitos
  return "+" . substr($real_number, 0, $tam - 11) . " (" . substr($real_number, $tam - 11, 2) . ") " . substr($real_number, $tam - 9, 5) . "-" . substr($real_number, -4);
 }
 if ($tam == 12) { // COM CÓDIGO DE ÁREA NACIONAL E DO PAIS
  return "+" . substr($real_number, 0, $tam - 10) . " (" . substr($real_number, $tam - 10, 2) . ") " . substr($real_number, $tam - 8, 4) . "-" . substr($real_number, -4);
 }
 if ($tam == 11) { // COM CÓDIGO DE ÁREA NACIONAL e 9 dígitos
  return " (" . substr($real_number, 0, 2) . ") " . substr($real_number, 2, 5) . "-" . substr($real_number, 7, 11);
 }
 if ($tam == 10) { // COM CÓDIGO DE ÁREA NACIONAL
  return " (" . substr($real_number, 0, 2) . ") " . substr($real_number, 2, 4) . "-" . substr($real_number, 6, 10);
 }
 if ($tam <= 9) { // SEM CÓDIGO DE ÁREA
  return substr($real_number, 0, $tam - 4) . "-" . substr($real_number, -4);
 }
}

function hour_format($hour)
{
 $newHour = explode(":", $hour);
 return $newHour[0] . ':' . $newHour[1];
}

function getRelativeTime($timestamp)
{
 $difference = strtotime(date('Y-m-d H:i:s')) - strtotime($timestamp);
 $periods    = ['segundo', 'minuto', 'hora', 'dia', 'semana', 'mês', 'ano', 'década'];
 $lengths    = [60, 60, 24, 7, 4.35, 12, 10];

 // This was in the past
 if ($difference >= 0) {
  $ending = 'atrás';
  // This was in the future
 } else if ($difference < 0) {
  $difference = -$difference;
  $ending = 'à frente';
 }

 $j = 0;
 while ($difference >= $lengths[$j] && $j < count($lengths)) {
  $difference /= $lengths[$j];
  $j++;
 }

 $difference = round($difference);

 if ($difference != 1) {
  if ($periods[$j] == 'mês') {
   $periods[$j] = 'meses';
  } else {
   $periods[$j] .= 's';
  }
 }

 $text = "$difference $periods[$j] $ending";

 return $text;
}
