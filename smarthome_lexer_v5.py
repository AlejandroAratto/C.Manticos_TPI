"""
=============================================================
  LEXER  - Lenguaje SMART HOME
  Grupo: C.manticos  -  UTN FRRe  -  2026
=============================================================
  Uso:
    Modo interactivo : python smarthome_lexer.py
    Desde archivo    : python smarthome_lexer.py archivo.smart
=============================================================
"""

import sys
import os

# ─────────────────────────────────────────────────────────────
#  TIPOS DE TOKEN
# ─────────────────────────────────────────────────────────────
TK_WHEN              = 'WHEN'
TK_IF                = 'IF'
TK_THEN              = 'THEN'
TK_ELSE              = 'ELSE'
TK_DO                = 'DO'
TK_END               = 'END'
TK_EVERY             = 'EVERY'
TK_AND               = 'AND'
TK_OR                = 'OR'
TK_NOT               = 'NOT'
TK_TRUE              = 'TRUE'
TK_FALSE             = 'FALSE'
TK_ON                = 'ON'
TK_OFF               = 'OFF'
TK_FRIO              = 'FRIO'
TK_CALOR             = 'CALOR'
TK_VENT              = 'VENT'
TK_COLOR_BLANCO      = 'COLOR_BLANCO'
TK_COLOR_ROJO        = 'COLOR_ROJO'
TK_COLOR_AZUL        = 'COLOR_AZUL'
TK_ATTR_ESTADO       = 'ATTR_ESTADO'
TK_ATTR_BRILLO       = 'ATTR_BRILLO'
TK_ATTR_COLOR        = 'ATTR_COLOR'
TK_ATTR_MODO         = 'ATTR_MODO'
TK_ATTR_TEMP_OBJ     = 'ATTR_TEMP_OBJ'
TK_ATTR_TEMP_ACT     = 'ATTR_TEMP_ACT'
TK_ATTR_POSICION     = 'ATTR_POSICION'
TK_ATTR_VOLUMEN      = 'ATTR_VOLUMEN'
TK_ATTR_MUTE         = 'ATTR_MUTE'
TK_ATTR_MENSAJE      = 'ATTR_MENSAJE'
TK_ATTR_EMAIL_NOTIF  = 'ATTR_EMAIL_NOTIF'
TK_ATTR_EMAIL        = 'ATTR_EMAIL'
TK_ATTR_ACTIVADA     = 'ATTR_ACTIVADA'
TK_ATTR_HORA         = 'ATTR_HORA'
TK_ATTR_FECHA        = 'ATTR_FECHA'
TK_SENSOR_TEMPERATURA_ID = 'SENSOR_TEMPERATURA_ID'
TK_SENSOR_HUMEDAD_ID     = 'SENSOR_HUMEDAD_ID'
TK_SENSOR_LUZ_ID         = 'SENSOR_LUZ_ID'
TK_SENSOR_MOVIMIENTO_ID  = 'SENSOR_MOVIMIENTO_ID'
TK_SENSOR_HUMO_ID        = 'SENSOR_HUMO_ID'
TK_FOCO_ID       = 'FOCO_ID'
TK_AIRE_ID       = 'AIRE_ID'
TK_PERSIANA_ID   = 'PERSIANA_ID'
TK_CERRADURA_ID  = 'CERRADURA_ID'
TK_RELOJ_ID      = 'RELOJ_ID'
TK_ALTAVOZ_ID    = 'ALTAVOZ_ID'
TK_ALARMA_ID     = 'ALARMA_ID'
TK_TEMPERATURA   = 'TEMPERATURA'
TK_PORCENTAJE    = 'PORCENTAJE'
TK_TIEMPO        = 'TIEMPO'
TK_ILUMINANCIA   = 'ILUMINANCIA'
TK_VALOR_HORA    = 'VALOR_HORA'
TK_VALOR_FECHA   = 'VALOR_FECHA'
TK_EMAIL         = 'EMAIL'
TK_TEXTO         = 'TEXTO'
TK_OP_EQ   = 'OP_EQ'
TK_OP_NEQ  = 'OP_NEQ'
TK_OP_GEQ  = 'OP_GEQ'
TK_OP_LEQ  = 'OP_LEQ'
TK_OP_GT   = 'OP_GT'
TK_OP_LT   = 'OP_LT'
TK_ASIGN   = 'ASIGN'
TK_PUNTO   = 'PUNTO'

# ─────────────────────────────────────────────────────────────
#  PALABRAS RESERVADAS
# ─────────────────────────────────────────────────────────────
PALABRAS_RESERVADAS = {
    'when'          : TK_WHEN,
    'if'            : TK_IF,
    'then'          : TK_THEN,
    'else'          : TK_ELSE,
    'do'            : TK_DO,
    'end'           : TK_END,
    'every'         : TK_EVERY,
    'and'           : TK_AND,
    'or'            : TK_OR,
    'not'           : TK_NOT,
    'true'          : TK_TRUE,
    'false'         : TK_FALSE,
    'on'            : TK_ON,
    'off'           : TK_OFF,
    'frio'          : TK_FRIO,
    'calor'         : TK_CALOR,
    'vent'          : TK_VENT,
    'blanco'        : TK_COLOR_BLANCO,
    'rojo'          : TK_COLOR_ROJO,
    'azul'          : TK_COLOR_AZUL,
    'blue'          : TK_COLOR_AZUL,
    'estado'        : TK_ATTR_ESTADO,
    'brillo'        : TK_ATTR_BRILLO,
    'color'         : TK_ATTR_COLOR,
    'modo'          : TK_ATTR_MODO,
    'temp_obj'      : TK_ATTR_TEMP_OBJ,
    'temp_objetivo' : TK_ATTR_TEMP_OBJ,
    'temp_act'      : TK_ATTR_TEMP_ACT,
    'posicion'      : TK_ATTR_POSICION,
    'volumen'       : TK_ATTR_VOLUMEN,
    'mute'          : TK_ATTR_MUTE,
    'mensaje'       : TK_ATTR_MENSAJE,
    'email_notif'   : TK_ATTR_EMAIL_NOTIF,
    'email'         : TK_ATTR_EMAIL,
    'activada'      : TK_ATTR_ACTIVADA,
    'hora'          : TK_ATTR_HORA,
    'fecha'         : TK_ATTR_FECHA,
}

# ─────────────────────────────────────────────────────────────
#  CLASES TOKEN Y ERROR
# ─────────────────────────────────────────────────────────────
class Token:
    def __init__(self, tipo, valor, linea):
        self.tipo  = tipo
        self.valor = valor
        self.linea = linea

class ErrorLexico:
    def __init__(self, mensaje, linea, cadena):
        self.mensaje = mensaje
        self.linea   = linea
        self.cadena  = cadena
    def __str__(self):
        return f"  [ERROR LEXICO] Linea {self.linea}: {self.mensaje} -> '{self.cadena}'"

# ─────────────────────────────────────────────────────────────
#  HELPERS DE CARACTERES
# ─────────────────────────────────────────────────────────────
def es_letra(c):
    return ('a' <= c <= 'z') or ('A' <= c <= 'Z') or c == '_'

def es_digito(c):
    return '0' <= c <= '9'

def es_alfanum(c):
    return es_letra(c) or es_digito(c)

def es_espacio(c):
    return c in (' ', '\t', '\r')

# ─────────────────────────────────────────────────────────────
#  LEXER
# ─────────────────────────────────────────────────────────────
class Lexer:
    def __init__(self, codigo):
        self.codigo  = codigo
        self.pos     = 0
        self.linea   = 1
        self.tokens  = []
        self.errores = []

    def actual(self):
        return self.codigo[self.pos] if self.pos < len(self.codigo) else None

    def siguiente(self):
        return self.codigo[self.pos + 1] if self.pos + 1 < len(self.codigo) else None

    def avanzar(self):
        c = self.codigo[self.pos]
        self.pos += 1
        if c == '\n':
            self.linea += 1
        return c

    def agregar_token(self, tipo, valor):
        self.tokens.append(Token(tipo, valor, self.linea))

    def agregar_error(self, mensaje, cadena):
        # solo acumula, NO imprime aqui
        self.errores.append(ErrorLexico(mensaje, self.linea, cadena))

    # ── punto de entrada ──────────────────────────────────
    def analizar(self):
        while self.pos < len(self.codigo):
            c = self.actual()

            if es_espacio(c):
                self.avanzar()
            elif c == '\n':
                self.avanzar()
            elif c == '/' and self.siguiente() == '/':
                self._leer_comentario()
            elif c == '"':
                self._leer_texto()
            elif es_digito(c) or (c == '-' and self.siguiente() and es_digito(self.siguiente())):
                self._leer_numero()
            elif c == '°':
                self.agregar_error("Simbolo '°' inesperado sin numero previo", c)
                self.avanzar()
            elif es_letra(c):
                self._leer_identificador()
            elif c == '=' and self.siguiente() == '=':
                self.avanzar(); self.avanzar()
                self.agregar_token(TK_OP_EQ, '==')
            elif c == '!' and self.siguiente() == '=':
                self.avanzar(); self.avanzar()
                self.agregar_token(TK_OP_NEQ, '!=')
            elif c == '>' and self.siguiente() == '=':
                self.avanzar(); self.avanzar()
                self.agregar_token(TK_OP_GEQ, '>=')
            elif c == '<' and self.siguiente() == '=':
                self.avanzar(); self.avanzar()
                self.agregar_token(TK_OP_LEQ, '<=')
            elif c == '>':
                self.avanzar(); self.agregar_token(TK_OP_GT, '>')
            elif c == '<':
                self.avanzar(); self.agregar_token(TK_OP_LT, '<')
            elif c == '=':
                self.avanzar(); self.agregar_token(TK_ASIGN, '=')
            elif c == '.':
                self.avanzar(); self.agregar_token(TK_PUNTO, '.')
            else:
                self.agregar_error(f"Caracter ilegal: '{c}'", c)
                self.avanzar()

        return self.tokens

    def _leer_comentario(self):
        while self.pos < len(self.codigo) and self.actual() != '\n':
            self.avanzar()

    def _leer_texto(self):
        self.avanzar()
        contenido = []
        while self.pos < len(self.codigo):
            c = self.actual()
            if c == '"':
                self.avanzar()
                self.agregar_token(TK_TEXTO, ''.join(contenido))
                return
            if c == '\n':
                break
            contenido.append(c)
            self.avanzar()
        self.agregar_error("Cadena de texto no cerrada", '"' + ''.join(contenido))

    def _leer_numero(self):
        negativo = False
        if self.actual() == '-':
            negativo = True
            self.avanzar()

        entero = []
        while self.pos < len(self.codigo) and es_digito(self.actual()):
            entero.append(self.avanzar())

        if not entero:
            self.agregar_error("Numero mal formado", '-')
            return

        entero_str  = ''.join(entero)
        decimal_str = ''
        if self.actual() == '.' and self.siguiente() and es_digito(self.siguiente()):
            self.avanzar()
            decimales = []
            while self.pos < len(self.codigo) and es_digito(self.actual()):
                decimales.append(self.avanzar())
            decimal_str = '.' + ''.join(decimales)

        prefijo = ('-' if negativo else '') + entero_str + decimal_str
        c = self.actual()

        # VALOR_HORA  HH:MM
        if c == ':' and not negativo and not decimal_str:
            self.avanzar()
            mm = []
            while self.pos < len(self.codigo) and es_digito(self.actual()):
                mm.append(self.avanzar())
            if len(mm) == 2:
                hh_v = int(entero_str)
                mm_v = int(''.join(mm))
                if 0 <= hh_v <= 23 and 0 <= mm_v <= 59:
                    self.agregar_token(TK_VALOR_HORA, prefijo + ':' + ''.join(mm))
                    return
            self.agregar_error("Hora invalida (esperado HH:MM 24h)",
                               prefijo + ':' + ''.join(mm))
            return

        # VALOR_FECHA  DD/MM/AAAA
        if c == '/' and not negativo and not decimal_str:
            self.avanzar()
            mes = []
            while self.pos < len(self.codigo) and es_digito(self.actual()):
                mes.append(self.avanzar())
            if self.actual() == '/':
                self.avanzar()
                anio = []
                while self.pos < len(self.codigo) and es_digito(self.actual()):
                    anio.append(self.avanzar())
                dd   = int(entero_str)
                mm_v = int(''.join(mes))  if mes  else 0
                aa   = int(''.join(anio)) if anio else 0
                if 1 <= dd <= 31 and 1 <= mm_v <= 12 and 1900 <= aa <= 2099:
                    self.agregar_token(TK_VALOR_FECHA,
                        f"{entero_str}/{''.join(mes)}/{''.join(anio)}")
                    return
            self.agregar_error("Fecha invalida (esperado DD/MM/AAAA)",
                               prefijo + '/...')
            return

        # TEMPERATURA  N°C
        if c == '°':
            self.avanzar()
            if self.actual() and self.actual().upper() == 'C':
                self.avanzar()
                self.agregar_token(TK_TEMPERATURA, prefijo + '°C')
                return
            self.agregar_error("Temperatura mal formada (esperado N°C)", prefijo + '°')
            return

        # PORCENTAJE  N%
        if c == '%':
            self.avanzar()
            self.agregar_token(TK_PORCENTAJE, prefijo + '%')
            return

        # ILUMINANCIA  Nlux
        if c and c.lower() == 'l':
            if self._intentar_sufijo('lux'):
                self.agregar_token(TK_ILUMINANCIA, prefijo + 'lux')
                return

        # TIEMPO  Ns / Nm / Nh
        if c in ('s', 'm', 'h') and not negativo:
            self.avanzar()
            self.agregar_token(TK_TIEMPO, prefijo + c)
            return

        self.agregar_error("Numero sin unidad valida", prefijo + (c if c else ''))
        if c and not es_letra(c) and c not in ('=','<','>','!','.','"','\n',' ','\t'):
            self.avanzar()

    def _intentar_sufijo(self, sufijo):
        if self.pos + len(sufijo) > len(self.codigo):
            return False
        fragmento = self.codigo[self.pos : self.pos + len(sufijo)]
        if fragmento.lower() == sufijo.lower():
            for _ in sufijo:
                self.avanzar()
            return True
        return False

    def _leer_identificador(self):
        chars = []
        while self.pos < len(self.codigo) and (es_alfanum(self.actual()) or self.actual() == '_'):
            chars.append(self.avanzar())

        if self.actual() == '@':
            self._continuar_email(chars)
            return

        lexema = ''.join(chars)
        lower  = lexema.lower()

        if lower in PALABRAS_RESERVADAS:
            self.agregar_token(PALABRAS_RESERVADAS[lower], lexema)
            return

        tipo = self._clasificar_dispositivo(lower)
        if tipo:
            self.agregar_token(tipo, lexema)
            return

        self.agregar_error(f"Identificador desconocido", lexema)

    def _continuar_email(self, parte_usuario):
        self.avanzar()   # consumir '@'
        dominio = []
        while self.pos < len(self.codigo) and \
              (es_alfanum(self.actual()) or self.actual() in ('_', '.', '+', '-')):
            dominio.append(self.avanzar())

        usuario = ''.join(parte_usuario)
        dom_str = ''.join(dominio)

        if '.' in dom_str:
            partes    = dom_str.rsplit('.', 1)
            extension = partes[1] if len(partes) == 2 else ''
            if (2 <= len(extension) <= 4 and
                    all(es_letra(ch) for ch in extension) and
                    len(partes[0]) > 0):
                self.agregar_token(TK_EMAIL, usuario + '@' + dom_str)
                return

        self.agregar_error("Email con formato invalido", usuario + '@' + dom_str)

    def _clasificar_dispositivo(self, lower):
        if lower.startswith('sensor_temp'):          return TK_SENSOR_TEMPERATURA_ID
        if lower.startswith('sensor_humedad'):       return TK_SENSOR_HUMEDAD_ID
        if lower.startswith('sensor_luz'):           return TK_SENSOR_LUZ_ID
        if lower.startswith('sensor_movimiento'):    return TK_SENSOR_MOVIMIENTO_ID
        if lower.startswith('sensor_humo'):          return TK_SENSOR_HUMO_ID
        if lower.startswith('foco_')      and len(lower) > 5:  return TK_FOCO_ID
        if lower.startswith('aire_')      and len(lower) > 5:  return TK_AIRE_ID
        if lower.startswith('persiana_')  and len(lower) > 9:  return TK_PERSIANA_ID
        if lower.startswith('cerradura_') and len(lower) > 10: return TK_CERRADURA_ID
        if lower.startswith('reloj_')     and len(lower) > 6:  return TK_RELOJ_ID
        if lower.startswith('altavoz_')   and len(lower) > 8:  return TK_ALTAVOZ_ID
        if lower.startswith('alarma_')    and len(lower) > 7:  return TK_ALARMA_ID
        if lower == 'reloj':  return TK_RELOJ_ID
        if lower == 'alarma': return TK_ALARMA_ID
        return None

# ─────────────────────────────────────────────────────────────
#  IMPRESION DE TABLA  (unica funcion de salida)
# ─────────────────────────────────────────────────────────────
SEP  = "=" * 68
SEP2 = "-" * 68

def imprimir_tabla(tokens, errores):
    print()
    print(SEP)
    print(f"  {'TIPO':<30} {'LEXEMA':<22} {'LINEA':>5}")
    print(SEP2)
    for tok in tokens:
        print(f"  {tok.tipo:<30} {str(tok.valor):<22} {tok.linea:>5}")
    print(SEP)
    print(f"  Tokens reconocidos : {len(tokens)}")
    if errores:
        print(f"  Errores lexicos    : {len(errores)}")
        print(SEP2)
        for e in errores:
            print(e)
    else:
        print("  Estado             : OK - Sin errores lexicos")
    print(SEP)
    print()

# ─────────────────────────────────────────────────────────────
#  MODO INTERACTIVO  (un solo bloque, tabla al final)
# ─────────────────────────────────────────────────────────────
BANNER = """
================================================================
   LEXER SMART HOME  -  C.manticos  -  UTN FRRe  -  2026
================================================================
 Ingrese el codigo y presione ENTER dos veces para analizar.
 Escriba 'salir' para terminar.
================================================================
"""

def modo_interactivo():
    print(BANNER)
    lineas = []
    try:
        while True:
            prompt = "  >>> " if not lineas else "  ... "
            try:
                linea = input(prompt)
            except EOFError:
                break

            if linea.strip().lower() == 'salir':
                print("\n  Hasta luego.\n")
                return

            # linea vacia con contenido => analizar
            if linea.strip() == '' and lineas:
                break

            # linea vacia sin contenido => ignorar
            if linea.strip() == '' and not lineas:
                continue

            lineas.append(linea)

    except KeyboardInterrupt:
        print()

    if not lineas:
        print("\n  No se ingreso codigo.\n")
        return

    codigo = "\n".join(lineas)
    lexer  = Lexer(codigo)
    lexer.analizar()
    imprimir_tabla(lexer.tokens, lexer.errores)

# ─────────────────────────────────────────────────────────────
#  MODO ARCHIVO
# ─────────────────────────────────────────────────────────────
def modo_archivo(path):
    if not path.lower().endswith('.smart'):
        print(f"\n  [ERROR] El archivo debe tener extension '.smart'")
        print(f"  Recibido: '{path}'\n")
        sys.exit(1)

    if not os.path.isfile(path):
        print(f"\n  [ERROR] Archivo no encontrado: '{path}'\n")
        sys.exit(1)

    with open(path, 'r', encoding='utf-8') as f:
        codigo = f.read()

    print(f"\n  Analizando: {path}")

    lexer = Lexer(codigo)
    lexer.analizar()
    imprimir_tabla(lexer.tokens, lexer.errores)

    # guardar reporte
    reporte = os.path.splitext(path)[0] + '_tokens.txt'
    with open(reporte, 'w', encoding='utf-8') as f:
        f.write(f"Reporte lexico: {path}\n")
        f.write(SEP + "\n")
        f.write(f"  {'TIPO':<30} {'LEXEMA':<22} {'LINEA':>5}\n")
        f.write(SEP2 + "\n")
        for tok in lexer.tokens:
            f.write(f"  {tok.tipo:<30} {str(tok.valor):<22} {tok.linea:>5}\n")
        f.write(SEP + "\n")
        f.write(f"  Tokens reconocidos : {len(lexer.tokens)}\n")
        if lexer.errores:
            f.write(f"  Errores lexicos    : {len(lexer.errores)}\n")
            f.write(SEP2 + "\n")
            for e in lexer.errores:
                f.write(f"{e}\n")
        else:
            f.write("  Estado             : OK - Sin errores lexicos\n")
        f.write(SEP + "\n")

    print(f"  Reporte guardado en: {reporte}\n")

# ─────────────────────────────────────────────────────────────
#  PUNTO DE ENTRADA
# ─────────────────────────────────────────────────────────────
if __name__ == '__main__':
    if len(sys.argv) == 1:
        modo_interactivo()
    elif len(sys.argv) == 2:
        modo_archivo(sys.argv[1])
    else:
        print("\nUso:")
        print("  python smarthome_lexer.py                 -> modo interactivo")
        print("  python smarthome_lexer.py archivo.smart   -> modo archivo\n")
        sys.exit(1)
