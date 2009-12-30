#! /usr/bin/python
# Check ASFormatter constructor to class variables
#     in the header file to verify all variables are initialized .

import sys
import os

# global variables ------------------------------------------------------------

print_detail = False				# print line numbers and total variables
print_variables = False			# print the variables in the lists

# -----------------------------------------------------------------------------

def process_files():
	"""Main processing function."""

	header_variables = []		# variables in astyle.h
	class_variables = []			# variables in the class constructor
	header_path = get_source_directory() + "/astyle.h"
	formatter_path = get_source_directory() + "/ASFormatter.cpp"

	get_header_variables(header_variables, header_path)
	get_constructor_variables(class_variables, formatter_path)
	get_initializer_variables(class_variables, formatter_path)
	header_variables.sort()
	class_variables.sort()
	remove_class_duplicates(class_variables)

	print "Checking ASFormatter header to class constructor."
	total_variables = len(header_variables)
	print "There are {0} variables in the header list.".format(total_variables)

	find_class_diffs(header_variables, class_variables)

	if print_variables:
		print header_variables
		print class_variables

# -----------------------------------------------------------------------------

def convert_class_functions(line):
	"""Convert class initializer functions to the corresponding variable."""
	first_paren = line.find('(')
	if first_paren == -1:
		return line
	if line.find("initContainer") != -1:
		line = line[first_paren + 1:]
		first_comma = line.find(',')
		if first_comma != -1:
			line = line[:first_comma]
		line = line.strip()
	# bypass static vector initialization
	elif line.find("initVector") != -1:
		line = ''
	elif line.find("->") != -1:
		line = ''
	elif line.find("buildLanguageVectors") != -1:
		line = ''
	elif line.find("fixOptionVariableConflicts") != -1:
		line = ''
	elif line.find("ASBeautifier::init") != -1:
		line = ''
	elif line.find("getCaseIndent") != -1:
		line = ''
	elif line.find("getEmptyLineFill") != -1:
		line = ''
	elif line.find("getIndentLength") != -1:
		line = ''
	elif line.find("getIndentString") != -1:
		line = ''
	else:
		line = "unidentified function: " + line
	return line

# -----------------------------------------------------------------------------

def find_class_diffs(header_variables, class_variables):
	"""Find differences in header and class variables lists."""
	diffs = 0
	i = 0
	j = 0

	# print "Checking ASFormatter header variables to class constructor."
	while i < len(header_variables):
		if ( j >= len(class_variables)
		or header_variables[i] < class_variables[j]):
			print "missing class: " + header_variables[i]
			diffs += 1
			i += 1
			continue
		if header_variables[i] > class_variables[j]:
			print "missing header: " + class_variables[j]
			diffs += 1
			j +=1
			continue
		i += 1
		j += 1

	# get extra class_variables
	while j < len(class_variables):
		print "missing header: " + class_variables[j]
		diffs += 1
		j += 1
		continue
	if diffs == 0:
		print "There are NO diffs in the class constructor variables!!!"
	else:
		print "There are {0} diffs in the class constructor variables.".format(diffs)

# -----------------------------------------------------------------------------

def get_constructor_variables(class_variables, formatter_path):
	"""Read the ASFormatter file and save the class constuctor variables."""

	class_lines = [0,0]		# line numbers for class constructor
	class_total = 0			# total variables for class constructor
	lines = 0					# current input line number
	file_in = open(formatter_path, 'r')

	# get class constructor lines
	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line[:2] == "//":
			continue
		# start between the following lines
		if line.find("ASFormatter::ASFormatter()") != -1:
			class_lines[0] = lines + 1
			continue
		if (class_lines[0]  == 0
		or class_lines[0]  >= lines):
			continue
		# find ending bracket
		if line.find('}') != -1:
			class_lines[1] = lines
			break
		# bypass static variable
		if line.find("formatterFileType") != -1:
			continue
		# get the variable name
		variable_name = line
		if line.find('(') != -1:
			variable_name = convert_class_functions(line)
		else:
			first_space = line.find(' ')
			if first_space != -1:
				variable_name = line[0:first_space].strip()
		if len(variable_name) == 0:
			continue
		class_variables.append(variable_name)
		class_total += 1

	file_in.close()
	if print_detail:
		print "{0} {1} class constructor".format(class_lines, class_total)

# -----------------------------------------------------------------------------

def get_header_variables(header_variables, header_path):
	"""Read the header file and save the ASFormatter variables."""

	header_lines = [0,0]		# line numbers for header
	header_total = 0			# total variables for header
	lines = 0					# current input line number
	file_in = open(header_path, 'r')

	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line[:2] == "//":
			continue

		# start between the following lines
		if line.find("class ASFormatter") != -1:
			header_lines[0] = lines + 1
			continue
		if (header_lines[0]  == 0
		or header_lines[0]  >= lines):
			continue
		# find ending bracket - should find following comment instead
		if line.find('}') != -1:
			header_lines[1] = lines
			break
		# find ending comment
		if line.find("// inline functions") != -1:
			header_lines[1] = lines
			break
		if (line.find("public:") != -1
		or line.find("private:") != -1
		or line.find("protected:") != -1):
			continue
		# bypass functions
		if (line.find('(') != -1
		or line.find(')') != -1):
			continue
		# bypass static variables
		if line[:6] == "static":
			continue
		# get the variable name
		semi_colon = line.find(';');
		if semi_colon == -1:
			continue
		last_space = line[:semi_colon].rfind(' ')
		if last_space == -1:
			continue
		variable_name = line[last_space:semi_colon].strip()
		if variable_name[0] == '*':
			variable_name = variable_name[1:]
		header_variables.append(variable_name)
		header_total += 1

	file_in.close()
	if print_detail:
		print "{0} {1} header".format(header_lines, header_total)

# -----------------------------------------------------------------------------

def get_initializer_variables(class_variables, formatter_path):
	"""Read the ASFormatter file and save the class initializer variables."""

	class_lines_init = [0,0]		# line numbers for class init() function
	class_total_init = 0			# total variables for class init() function
	lines_init = 0					# current input line number
	file_in_init = open(formatter_path, 'r')

	# get class initializer lines
	for line_in in file_in_init:
		lines_init += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line[:2] == "//":
			continue
		# start between the following lines
		if line.find("void ASFormatter::init(ASSourceIterator") != -1:
			class_lines_init[0] = lines_init + 1
			continue
		if (class_lines_init[0]  == 0
		or class_lines_init[0]  >= lines_init):
			continue
		# find ending bracket
		if line.find('}') != -1:
			class_lines_init[1] = lines_init
			break
		# get the variable name
		variable_name = line
		if line.find('(') != -1:
			variable_name = convert_class_functions(line)
		else:
			first_space = line.find(' ')
			if first_space != -1:
				variable_name = line[:first_space].strip()
		if len(variable_name) == 0:
			continue
		class_variables.append(variable_name)
		class_total_init += 1

	file_in_init.close()
	if print_detail:
		print "{0} {1} class initializer".format(class_lines_init, class_total_init)

# -----------------------------------------------------------------------------

def get_source_directory():
	"""Get the AStyle/src directory for the os environment"""
	#~ if os.name == "nt":
		#~ return os.getenv("USERPROFILE") + "/Projects/AStyle/src"
	#~ else:
		#~ return os.getenv("HOME") + "/Projects/AStyle/src"
	return "../../AStyle/src"

# -----------------------------------------------------------------------------

def remove_class_duplicates(class_variables):
	"""Remove duplicates in class variables list."""
	class_duplicates = 0			# total number of class duplicates removed
	i = 1
	while i < len(class_variables):
		if class_variables[i - 1] == class_variables[i]:
			class_variables.remove(class_variables[i])
			class_duplicates += 1
			continue
		i +=1
	if print_detail:
		print " -{0} class duplicates".format(class_duplicates)

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_files()
	# pause if script is not run from SciTE (argv[1] = 'scite')
	if (os.name == "nt"
	and len(sys.argv) == 1):
		print
		os.system("pause")
		# raw_input("\nPress Enter to continue . . .")

# -----------------------------------------------------------------------------