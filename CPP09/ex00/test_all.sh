#!/bin/bash

# Bitcoin Exchange - Script de Pruebas Automatizado
# Ejecuta todos los casos de prueba y muestra resultados organizados

# Colores para output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Función para mostrar separador
separator() {
    echo -e "${CYAN}=================================================${NC}"
}

# Función para mostrar header
header() {
    echo -e "${PURPLE}$1${NC}"
    separator
}

# Verificar que el programa existe
if [ ! -f "./btc" ]; then
    echo -e "${RED}Error: Programa 'btc' no encontrado. Ejecuta 'make' primero.${NC}"
    exit 1
fi

# Verificar que el directorio input existe
if [ ! -d "./input" ]; then
    echo -e "${RED}Error: Directorio 'input' no encontrado.${NC}"
    exit 1
fi

clear
echo -e "${BLUE}╔══════════════════════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║                   BITCOIN EXCHANGE TESTER                    ║${NC}"
echo -e "${BLUE}║                     Automated Testing                        ║${NC}"
echo -e "${BLUE}╚══════════════════════════════════════════════════════════════╝${NC}"
echo ""

# 1. CASOS VÁLIDOS COMPLETOS
header "1. CASOS VÁLIDOS COMPLETOS (112 casos)"
echo -e "${GREEN}Archivo: input/comprehensive_valid_input.txt${NC}"
echo ""

if [ -f "./input/comprehensive_valid_input.txt" ]; then
    valid_count=$(./btc input/comprehensive_valid_input.txt | wc -l)
    echo -e "${GREEN}✅ Casos procesados: $valid_count${NC}"
    echo ""
    echo -e "${YELLOW}Primeras 10 líneas:${NC}"
    ./btc input/comprehensive_valid_input.txt | head -10
    echo ""
    echo -e "${YELLOW}Últimas 5 líneas:${NC}"
    ./btc input/comprehensive_valid_input.txt | tail -5
else
    echo -e "${RED}❌ Archivo no encontrado${NC}"
fi

echo ""
separator
read -p "Presiona Enter para continuar..."

# 2. CASOS DE ERROR
header "2. CASOS DE ERROR (82+ casos)"
echo -e "${RED}Archivo: input/error_cases.txt${NC}"
echo ""

if [ -f "./input/error_cases.txt" ]; then
    ./btc input/error_cases.txt > /tmp/error_results.txt 2>&1
    error_count=$(grep -c "Error" /tmp/error_results.txt)
    valid_in_error=$(grep -v "Error" /tmp/error_results.txt | wc -l)
    total_lines=$(wc -l < /tmp/error_results.txt)

    echo -e "${RED}🔴 Errores detectados: $error_count${NC}"
    echo -e "${GREEN}🟢 Casos válidos: $valid_in_error${NC}"
    echo -e "${BLUE}📊 Total líneas: $total_lines${NC}"
    echo ""
    echo -e "${YELLOW}Tipos de errores encontrados:${NC}"
    grep "Error" /tmp/error_results.txt | sort | uniq -c | sort -nr
    echo ""
    echo -e "${YELLOW}Primeras 15 líneas del resultado:${NC}"
    head -15 /tmp/error_results.txt
    rm -f /tmp/error_results.txt
else
    echo -e "${RED}❌ Archivo no encontrado${NC}"
fi

echo ""
separator
read -p "Presiona Enter para continuar..."

# 3. ARCHIVO DEL SUBJECT
header "3. ARCHIVO DEL SUBJECT (casos mixtos)"
echo -e "${BLUE}Archivo: input/input.txt${NC}"
echo ""

if [ -f "./input/input.txt" ]; then
    echo -e "${YELLOW}Resultado completo:${NC}"
    ./btc input/input.txt
else
    echo -e "${RED}❌ Archivo no encontrado${NC}"
fi

echo ""
separator
read -p "Presiona Enter para continuar..."

# 4. CASOS LÍMITE
header "4. CASOS LÍMITE (45 casos)"
echo -e "${CYAN}Archivo: input/edge_cases_valid.txt${NC}"
echo ""

if [ -f "./input/edge_cases_valid.txt" ]; then
    edge_count=$(./btc input/edge_cases_valid.txt | wc -l)
    echo -e "${GREEN}✅ Casos procesados: $edge_count${NC}"
    echo ""
    echo -e "${YELLOW}Primeras 10 líneas:${NC}"
    ./btc input/edge_cases_valid.txt | head -10
    echo ""
    echo -e "${YELLOW}Últimas 10 líneas:${NC}"
    ./btc input/edge_cases_valid.txt | tail -10
else
    echo -e "${RED}❌ Archivo no encontrado${NC}"
fi

echo ""
separator
read -p "Presiona Enter para continuar..."

# 5. CASOS BÁSICOS
header "5. CASOS BÁSICOS VÁLIDOS (51 casos)"
echo -e "${GREEN}Archivo: input/valid_input.txt${NC}"
echo ""

if [ -f "./input/valid_input.txt" ]; then
    basic_count=$(./btc input/valid_input.txt | wc -l)
    echo -e "${GREEN}✅ Casos procesados: $basic_count${NC}"
    echo ""
    echo -e "${YELLOW}Muestra de resultados:${NC}"
    ./btc input/valid_input.txt | head -15
else
    echo -e "${RED}❌ Archivo no encontrado${NC}"
fi

echo ""
separator
read -p "Presiona Enter para continuar..."

# 6. CASOS SIMPLES
header "6. CASOS SIMPLES (8 casos)"
echo -e "${GREEN}Archivo: input/test_input.txt${NC}"
echo ""

if [ -f "./input/test_input.txt" ]; then
    echo -e "${YELLOW}Resultado completo:${NC}"
    ./btc input/test_input.txt
else
    echo -e "${RED}❌ Archivo no encontrado${NC}"
fi

echo ""
separator

# 7. RESUMEN FINAL
header "7. RESUMEN FINAL"

echo -e "${BLUE}📊 ESTADÍSTICAS DE PRUEBAS:${NC}"
echo ""

# Contar archivos disponibles
files_found=0
total_files=6

[ -f "./input/comprehensive_valid_input.txt" ] && files_found=$((files_found + 1))
[ -f "./input/error_cases.txt" ] && files_found=$((files_found + 1))
[ -f "./input/input.txt" ] && files_found=$((files_found + 1))
[ -f "./input/edge_cases_valid.txt" ] && files_found=$((files_found + 1))
[ -f "./input/valid_input.txt" ] && files_found=$((files_found + 1))
[ -f "./input/test_input.txt" ] && files_found=$((files_found + 1))

echo -e "${GREEN}✅ Archivos de prueba encontrados: $files_found/$total_files${NC}"

if [ -f "./input/comprehensive_valid_input.txt" ]; then
    comprehensive_total=$(./btc input/comprehensive_valid_input.txt | wc -l)
    echo -e "${GREEN}✅ Casos válidos totales: $comprehensive_total${NC}"
fi

if [ -f "./input/error_cases.txt" ]; then
    ./btc input/error_cases.txt > /tmp/final_errors.txt 2>&1
    final_errors=$(grep -c "Error" /tmp/final_errors.txt)
    echo -e "${RED}🔴 Casos de error detectados: $final_errors${NC}"
    rm -f /tmp/final_errors.txt
fi

echo ""
echo -e "${PURPLE}🎯 COBERTURA DE PRUEBAS:${NC}"
echo -e "${GREEN}  ✓ Fechas exactas en base de datos${NC}"
echo -e "${GREEN}  ✓ Fechas intermedias (búsqueda anterior)${NC}"
echo -e "${GREEN}  ✓ Valores límite (0, 1000)${NC}"
echo -e "${GREEN}  ✓ Decimales y enteros${NC}"
echo -e "${GREEN}  ✓ Manejo de errores robusto${NC}"
echo -e "${GREEN}  ✓ Validación de fechas${NC}"
echo -e "${GREEN}  ✓ Validación de valores${NC}"

echo ""
echo -e "${BLUE}📖 Para más información, consulta:${NC}"
echo -e "${YELLOW}  - input/README.md${NC}"
echo -e "${YELLOW}  - input/test_cases_explanation.md${NC}"

echo ""
separator
echo -e "${GREEN}🎉 PRUEBAS COMPLETADAS${NC}"
separator
