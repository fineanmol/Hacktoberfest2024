program tictactoe;
{
  Simple jeu realisee par mohamed Aziz knani
}
uses wincrt, winprocs;

type
  tab = array [1..9] of string;
  
var
  countPartie, scoreJoueur1, scoreJoueur2   : integer;
  nomJoueur1, nomJoueur2                    : string;
  symJoueur1, symJoueur2, rep               : char;
  bool                                      : boolean;
  t                                         : tab;
  choix                                     : byte;

(* procedure delay pour faire un sleep
 * source -> http://www.developpez.net/forums/d1252400/autres-langages/pascal/turbo-pascal/procedure-delay-gettickcount/
*)
procedure Delay(Millisecond:Integer);
var
  fin:LongInt;
begin
  fin:=GetTickCount+(Millisecond);
 
  repeat
  until GetTickCount>=fin;
end;
    
procedure joueur(var nom : string; var sym, symJoueur1 : char; nbJoueur : byte) ;
begin
  write('Entrer le nom du joueur ', nbJoueur, ' -> ');
  readln(nom);
  if nbJoueur = 1 then 
    repeat
      write('X ou O -> ');
      readln(sym);
      sym := upCase(sym);
    until (sym = 'X') or (sym = 'O')
  else 
    if symJoueur1 = 'O' then
      sym := 'X'
    else sym := 'O';
end;


procedure jeu(t : tab; nomJoueur1, nomJoueur2 : string; symJoueur1, symJoueur2 : char;
               var scoreJoueur1, scoreJoueur2 : integer; mode : byte);
var
  tour                        : integer;
  a, tourJoueur1, tourJoueur2 : boolean;

function compare(valeur1, valeur2, valeur3 : string; var st : string) : boolean;
begin
  compare := false;
  (*writeln(valeur1, valeur2, valeur3); *)
  
  if ((valeur1 <> '') and (valeur2 <> '')) and (valeur3 <> '') then
      if ((valeur1 = valeur2) and (valeur1 = valeur3)) and (valeur2 = valeur3) then
        (* Moripon !!! *)
        begin
          compare := true;
          st := valeur1;
        end
  else
    compare := false;
end;


procedure affichage(t : tab; scoreJoueur1, scoreJoueur2 : integer);
var
  i, x, y : byte;

procedure inserer(x, y : byte; sym : char);
begin
  gotoxy(y, x);
  write(sym);
  gotoxy(1, 11);
end;

begin
  clrscr;
  write('       ', symJoueur1, ' % ', nomJoueur1, ' : ', scoreJoueur1, ' | ', 
         symJoueur2, ' % ', nomJoueur2, ' : ', scoreJoueur2);
  writeln;
  writeln;
  writeln('                  ---|---|---');
  writeln('                   1 | 2 | 3 ');
  writeln('                  ---|---|---');
  writeln('                   4 | 5 | 6 ');
  writeln('                  ---|---|---');
  writeln('                   7 | 8 | 9 ');
  writeln('                  ---|---|---');
  writeln;
  for i:=1 to 9 do
    begin
      if t[i] <> '' then 
      begin
          case i of
            1..3 : x := 4;
            4..6 : x := 6;
            7..9 : x := 8;
          end;
          case i of
            1, 4, 7 : y := 20;
            2, 5, 8 : y := 24;
            3, 6, 9 : y := 28;
          end;
        if t[i] = '1' then
          inserer(x, y, symJoueur1)
        else
          inserer(x, y, symJoueur2)
      end;
    end;
end;

procedure check(t : tab;var a: boolean;var scoreJoueur1, scoreJoueur2 : integer);
var
  ega, st : string;
  i       : integer;  
begin
  if compare(t[1], t[2], t[3], st) or compare(t[4], t[5], t[6], st) or compare(t[7], t[8], t[9], st)
   or compare(t[1], t[4], t[7], st) or compare(t[2], t[5], t[8], st) or compare(t[3], t[6], t[9], st)
   or compare(t[1], t[5], t[9], st) or compare(t[3], t[5], t[7], st) then
    begin
      a := false;
      if st = '1' then
        begin
          scoreJoueur1 := scoreJoueur1 + 1;
          Writeln(nomJoueur1, ' vous avez gagner !'); 
        end
       else
         begin
           scoreJoueur2 := scoreJoueur2 + 1;
           Writeln(nomJoueur2, ' vous avez gagner !'); 
         end;
   end;
   ega := '';
   for i:=1 to 9 do
     ega := ega + t[i];
   if (length(ega) = 9 ) and (st = '') then
     begin
       a := false;
       writeln('Egalite !');
     end;
end;

procedure saisieCase(var t : tab; nomJoueur : string; joueur : byte );
var
  choix : byte;
  cho   : boolean;

function difficile(t : tab) : byte;
var
  st : byte;

function com(c1, c2, c3 : string; n1, n2, n3 : byte; var foo : byte) : boolean;
begin
  if (c1 = c2) and (c3 = '') then 
    begin 
      foo := n3;
      com := True;
    end
  else if (c1 = c3) and (c2 = '') then 
    begin 
      foo := n2;
      com := True;
    end
  else if (c2 = c3) and (c1 = '') then 
    begin
      foo := n1;
      com := True;
    end
  else 
    com := False;
end;

begin
  if com(t[1], t[2], t[3], 1, 2, 3, st) or com(t[4], t[5], t[6], 4, 5, 6, st) or com(t[7], t[8], t[9], 7, 8, 9, st)
  or com(t[1], t[4], t[7], 1, 4, 7, st) or com(t[2], t[5], t[8], 2, 5, 8, st) or com(t[3], t[6], t[9], 3, 6, 9, st)
  or com(t[1], t[5], t[9], 1, 5, 9, st) or com(t[3], t[5], t[7], 3, 5, 7, st) then
     begin
     difficile := st;
     writeln(st); 
     end
  else 
    begin
      randomize;
      difficile := random(9) + 1;
    end;
end;

begin
  repeat
    cho := false;
    if not(joueur in [2..3]) then
      begin
        write(nomJoueur, ' entrer un nombre entre [1, 9] -> ');readln(choix);
      end
    else 
      if joueur = 2 then
        begin
          randomize;
          Delay(200);
          choix := random(9) + 1;
        end
    else
      if joueur = 3 then 
        begin    
         Delay(200);
         choix := difficile(t);
        end;
    if t[choix] = '' then
      begin
        if joueur = 1 then
           t[choix] := '1'
        else t[choix] := '0';
        cho := true;
      end;
  until (choix in [1..9]) and cho;
end;

begin
  a := true;
  randomize;
  tour := random(2);
  if tour = 1 then
	begin
	  tourJoueur1 := true;
	  tourJoueur2 := false;
	end
  else
	begin
	  tourJoueur1 := false;
	  tourJoueur2 := true;
	end;
  while a do
    begin
      affichage(t, scoreJoueur1, scoreJoueur2);
      if tourJoueur1 then
        begin
          saisieCase(t, nomJoueur1, 1);
          tourJoueur1 := false;
          tourJoueur2 := true;
        end;
      affichage(t, scoreJoueur1, scoreJoueur2);
      check(t, a, scoreJoueur1, scoreJoueur2);
      if a then
        begin
          if tourJoueur2 then
            begin
              if mode = 1 then
                mode := 0;
              saisieCase(t, nomJoueur2, mode);
              tourJoueur1 := true;
              tourJoueur2 := false;
            end;
        affichage(t, scoreJoueur1, scoreJoueur2);
        check(t, a, scoreJoueur1, scoreJoueur2);
    end;
   end;
end;

BEGIN
  repeat
    clrscr;
    writeln('          +---------------------------------------+');
    writeln('          |           JEU de Tic Tac Toe          |');
    writeln('          +---------------------------------------+');
    writeln;
    writeln;
    writeln('          1) Joueur VS Joueur                      ');
    writeln('          2) Joueur VS Machine (niveau facile)     ');
    writeln('          3) Joueur VS Machine (niveau difficile)  ');
    writeln;
    writeln;
    write  ('          Entrer un Choix > ');readln(choix);
  until choix in [1..3];
  repeat
    countPartie := countPartie + 1;
    if countPartie = 1 then 
      if choix = 1 then
        begin
          joueur(nomJoueur1, symJoueur1, symJoueur1, 1);
          joueur(nomJoueur2, symJoueur2, symJoueur1, 2);
        end
      else 
        begin
          joueur(nomJoueur1, symJoueur1, symJoueur1, 1);
          nomJoueur2 := 'Machine';
          if symJoueur1 = 'X' then 
            symJoueur2 := 'O'
          else
            symJoueur2 := 'X';          
        end;
    jeu(t, nomJoueur1, nomJoueur2, symJoueur1, symJoueur2, scoreJoueur1, scoreJoueur2, choix);
    write('Une autre partie [Y/n] -> ');
    read (rep); 
    rep := upCase(rep);
    if rep = 'Y' then 
      bool := true
    else bool := false;
  until bool = false ;
  clrScr;
  if scoreJoueur1 > scoreJoueur2 then
    writeln('Bien Joue ', nomJoueur1)
  else
  if scoreJoueur2 > scoreJoueur1 then
    writeln('Bien Joue ', nomJoueur2); 
END.
