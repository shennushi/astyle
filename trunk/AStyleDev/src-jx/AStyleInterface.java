// AStyleInterface.java

import java.util.*;

/**
 * The AStyleInterface class contains the variables and methods to call the
 * Artistic Style shared library to format a source file.
 */

public class AStyleInterface
{   // bracketStyle valid bracket styles
    public static final int STYLE_NONE       = 0;
    public static final int STYLE_ALLMAN     = 1;
    public static final int STYLE_JAVA       = 2;
    public static final int STYLE_KandR      = 3;
    public static final int STYLE_STROUSTRUP = 4;
    public static final int STYLE_WHITESMITH = 5;
    public static final int STYLE_BANNER     = 6;
    public static final int STYLE_GNU        = 7;
    public static final int STYLE_LINUX      = 8;
    public static final int STYLE_HORSTMANN  = 9;
    public static final int STYLE_1TBS       = 10;
    public static final int STYLE_PICO       = 11;
    public static final int STYLE_LISP       = 12;

    // indentType valid indent types
    public static final int INDENT_SPACES = 0;
    public static final int INDENT_TABS   = 1;
    public static final int INDENT_FTABS  = 2;

    // alignPointers valid pointer alignments
    public static final int ALIGN_NONE     = 0;
    public static final int ALIGN_TYPE     = 1;
    public static final int ALIGN_MIDDLE   = 2;
    public static final int ALIGN_NAME     = 3;

    // minConditionalOption valid options
    public static final int  MINCOND_ZERO = 0;
    public static final int  MINCOND_ONE = 1;
    public static final int  MINCOND_TWO = 2;
    public static final int  MINCOND_ONEHALF = 3;

    // fileMode variable file modes
    public static final int FILEMODE_CPP   = 0;
    public static final int FILEMODE_JAVA  = 1;
    public static final int FILEMODE_SHARP = 2;

    // option variable names are ALMOST the same as Artistic Style
    // the initial value is the default value in Artistic Style
    // comments are the command line option used to set the variable

    // bracket style option
    private int     bracketStyle = STYLE_NONE;   // --style=?

    // tabs/spaces options
    private int     indentLength = 4;               // --indent=?, --indent=force-tab=#
    private int     indentType   = INDENT_SPACES;   // --indent=?, --indent=force-tab=#

    // indentation options
    private boolean classIndent        = false;     // --indent-classes
    private boolean switchIndent       = false;     // --indent-switches
    private boolean caseIndent         = false;     // --indent-cases
    private boolean namespaceIndent    = false;     // --indent-namespaces
    private boolean labelIndent        = false;     // --indent-labels
    private boolean preprocessorIndent = false;     // --indent-preprocessor
    private boolean col1CommentIndent  = false;     // --indent-col1-comments
    private int maxInStatementIndent   = 40;        // --max-instatement-indent=#
    private int minConditionalOption = MINCOND_TWO; // --min-conditional-indent=#

    // padding options
    private boolean breakHeaderBlocks   = false;    // --break-blocks, --break-blocks=all
    private boolean breakClosingBlocks  = false;    // --break-blocks=all
    private boolean padOperators        = false;    // --pad-oper
    private boolean padParensOutside    = false;    // --pad-paren, --pad-paren-out
    private boolean padParensInside     = false;    // --pad-paren, --pad-paren-in
    private boolean padHeaders          = false;    // --pad-header
    private boolean unpadParens         = false;    // --unpad-paren
    private boolean deleteEmptyLines    = false;    // --delete-empty-lines
    private boolean fillEmptyLines      = false;    // --fill-empty-lines

    // formatting options
    private boolean breakCloseBrackets   = false;   // --break-closing-brackets
    private boolean breakElseIfs         = false;   // --break-elseifs
    private boolean addBrackets          = false;   // --add-brackets
    private boolean addOneLineBrackets   = false;   // --add-one-line-brackets
    private boolean breakOneLineStmts    = true;    // --keep-one-line-statements
    private boolean breakOneLineBlocks   = true;    // --keep-one-line-blocks
    private boolean convertTabs          = false;   // --convert-tabs
    private int     alignPointers        = ALIGN_NONE; // align-pointer= none, type, middle, name

    // file mode option
    private int     fileMode = FILEMODE_CPP;        // --mode=?

    // default values for integer variables, saved by constructor
    private int    defaultIndentLength;             // default indentLength
    private int    defaultMaxInStatementIndent;     // default maxInStatementIndent
    private int    defaultMinConditionalOption;     // default minConditionalOption

    /**
    * The constructor saves the integer default values.
    * A static constructor loads the native Artistic Style library.
    **/
    public AStyleInterface()
    {   // save integer default values
        defaultIndentLength         = indentLength;
        defaultMaxInStatementIndent = maxInStatementIndent;
        defaultMinConditionalOption = minConditionalOption;
    }

    /**
     * Displays error messages for the class.
     * This method should be changed to display messages in a manner consistent
     * with the rest of the user program (e.g. a message box).
     *
     * @param  errorMessage   The error message to be displayed.
      */
    private static void displayErrorMessage(String errorMessage)
    {   System.out.println(errorMessage);
    }

    /**
    * Builds a string of options from the current option variables.
    * An option is generated only if the current value is different
    * than the default value.
    * If an option variable is invalid, invalid text is sent to
    * Artistic Style so the private ErrorHandler method will be called.
    *
    * @return    A String containing the options for Artistic Style.
    **/
    public String getOptions()
    {   StringBuffer options =  new StringBuffer(50);  // options to Artistic Style
        String separator = "\n";                       // can be new-line, tab, space, or comma

        // bracket style will override other options
        if (bracketStyle != STYLE_NONE)
        {   if (bracketStyle == STYLE_ALLMAN)
                options.append("style=allman");
            else if (bracketStyle == STYLE_JAVA)
                options.append("style=java");
            else if (bracketStyle == STYLE_KandR)
                options.append("style=k&r");
            else if (bracketStyle == STYLE_STROUSTRUP)
                options.append("style=stroustrup");
            else if (bracketStyle == STYLE_WHITESMITH)
                options.append("style=whitesmith");
            else if (bracketStyle == STYLE_BANNER)
                options.append("style=banner");
            else if (bracketStyle == STYLE_GNU)
                options.append("style=gnu");
            else if (bracketStyle == STYLE_LINUX)
                options.append("style=linux");
            else if (bracketStyle == STYLE_HORSTMANN)
                options.append("style=horstmann");
            else if (bracketStyle == STYLE_1TBS)
                options.append("style=1tbs");
            else if (bracketStyle == STYLE_PICO)
                options.append("style=pico");
            else if (bracketStyle == STYLE_LISP)
                options.append("style=lisp");
            else
                options.append("bracketStyle="      // force an error message
                               + String.valueOf(bracketStyle));
            options.append(separator);
        }
        // begin indent check
        if (indentType == INDENT_SPACES)               // space is the default
        {   if (indentLength != defaultIndentLength)
            {   options.append("indent=spaces=" + String.valueOf(indentLength));
                options.append(separator);
            }
        }
        else if (indentType == INDENT_TABS)            // tab is not the default
        {   // check conditions to use default tab setting
            if (indentLength == defaultIndentLength)
                options.append("indent=tab");
            else
                options.append("indent=tab=" + String.valueOf(indentLength));
            options.append(separator);
        }
        else if (indentType == INDENT_FTABS)
        {   options.append("indent=force-tab=" + String.valueOf(indentLength));
            options.append(separator);
        }
        else
        {   options.append("indentType="               // force an error message
                           + String.valueOf(indentType));
            options.append(separator);
        }
        // end indent check
        if (classIndent)
        {   options.append("indent-classes");
            options.append(separator);
        }
        if (switchIndent)
        {   options.append("indent-switches");
            options.append(separator);
        }
        if (caseIndent)
        {   options.append("indent-cases");
            options.append(separator);
        }
        if (namespaceIndent)
        {   options.append("indent-namespaces");
            options.append(separator);
        }
        if (labelIndent)
        {   options.append("indent-labels");
            options.append(separator);
        }
        if (preprocessorIndent)
        {   options.append("indent-preprocessor");
            options.append(separator);
        }
        if (col1CommentIndent)
        {   options.append("indent-col1-comments");
            options.append(separator);
        }
        if (maxInStatementIndent != defaultMaxInStatementIndent)
        {   options.append("max-instatement-indent="
                           + String.valueOf(maxInStatementIndent));
            options.append(separator);
        }
        if (minConditionalOption != defaultMinConditionalOption)
        {   options.append("min-conditional-indent="
                           + String.valueOf(minConditionalOption));
            options.append(separator);
        }
        // begin break-blocks check
        if (breakClosingBlocks)
        {   options.append("break-blocks=all");
            options.append(separator);
        }
        else if (breakHeaderBlocks)
        {   options.append("break-blocks");
            options.append(separator);
        }
        // end break-blocks check
        if (padOperators)
        {   options.append("pad-oper");
            options.append(separator);
        }
        // begin pad parens check
        if (padParensOutside && padParensInside)
        {   options.append("pad-paren");
            options.append(separator);
        }
        else if (padParensOutside)
        {   options.append("pad-paren-out");
            options.append(separator);
        }
        else if (padParensInside)
        {   options.append("pad-paren-in");
            options.append(separator);
        }
        // end pad parens check
        if (padHeaders)
        {   options.append("pad-header");
            options.append(separator);
        }
        if (unpadParens)
        {   options.append("unpad-paren");
            options.append(separator);
        }
        if (deleteEmptyLines)
        {   options.append("delete-empty-lines");
            options.append(separator);
        }
        if (fillEmptyLines)
        {   options.append("fill-empty-lines");
            options.append(separator);
        }
        if (breakCloseBrackets)
        {   options.append("break-closing-brackets");
            options.append(separator);
        }
        if (breakElseIfs)
        {   options.append("break-elseifs");
            options.append(separator);
        }
        if (addBrackets)
        {   options.append("add-brackets");
            options.append(separator);
        }
        if (addOneLineBrackets)
        {   options.append("add-one-line-brackets");
            options.append(separator);
        }
        if (! breakOneLineStmts)               // default = true
        {   options.append("keep-one-line-statements");
            options.append(separator);
        }
        if (! breakOneLineBlocks)              // default = true
        {   options.append("keep-one-line-blocks");
            options.append(separator);
        }
        if (convertTabs)
        {   options.append("convert-tabs");
            options.append(separator);
        }
        // begin align pointers check
        if (alignPointers == ALIGN_TYPE)
        {   options.append("align-pointer=type");
            options.append(separator);
        }
        else if (alignPointers == ALIGN_MIDDLE)
        {   options.append("align-pointer=middle");
            options.append(separator);
        }
        else if (alignPointers == ALIGN_NAME)
        {   options.append("align-pointer=name");
            options.append(separator);
        }
        // end align pointers check
        // add the file mode, default is C++
        if (fileMode == FILEMODE_CPP)
        {   if (options.length() > 0)          // delete the last separator
                options.deleteCharAt(options.length()-1);
        }
        else if (fileMode == FILEMODE_JAVA)
            options.append("mode=java");
        else if (fileMode == FILEMODE_SHARP)
            options.append("mode=cs");
        else
            options.append("fileMode="         // force an error message
                           + String.valueOf(fileMode));

        return options.toString();
    }

    /**
    * Set the fileMode variable from the input file extension.
    *
    * @param  fileName   The name of the file, path may be included.
    */
    public void setFileMode(String fileName)
    {   fileMode = FILEMODE_CPP;
        if (fileName.endsWith(".java"))
            fileMode = FILEMODE_JAVA;
        else if (fileName.endsWith(".cs"))
            fileMode = FILEMODE_SHARP;
    }

    /**
    * Set options for testing.
    * For test program only.
    * Calls the private setTestOptionsX().
    */
    public void setTestOptions()
    {   setTestOptionsX();
    }

    /**
    * Set options for testing.
    * For test program only.
    * This will not be used by an actual program.
    */
    private void setTestOptionsX()
    {   // bracket Style options
        bracketStyle = STYLE_NONE;

        // tabs / spaces options
        indentLength = 3;
        indentType   = INDENT_TABS;

        // fileMode option - FILEMODE_JAVA is required for Java files
        fileMode = FILEMODE_JAVA;

        // indentation options
        classIndent          = true;
        switchIndent         = true;
        caseIndent           = true;
        namespaceIndent      = true;
        labelIndent          = true;
        preprocessorIndent   = true;
        col1CommentIndent    = true;
        maxInStatementIndent = 50;
        minConditionalOption = 0;

        // padding options
        breakHeaderBlocks    = true;
        breakClosingBlocks   = true;
        padOperators         = true;
        padParensOutside     = true;
        padParensInside      = true;
        padHeaders           = true;
        unpadParens          = true;
        deleteEmptyLines     = true;
        fillEmptyLines       = true;

        // formatting options
        breakCloseBrackets   = true;
        breakElseIfs         = true;
        addBrackets          = true;
        addOneLineBrackets   = true;
        breakOneLineStmts    = false;
        breakOneLineBlocks   = false;
        convertTabs          = true;
        alignPointers        = ALIGN_TYPE;

        // generate some errors
        /*  bracketStyle   = 20;
        maxInStatementIndent = 90;
        minConditionalOption = 9;
        // cannot have both invalid indentLength and invalid indentType
        //indentLength      = 21;
        indentType        = 6;  */
    }

    // methods to call Artistic Style ---------------------------------------------------

    /**
    * Static constructor to load the native Artistic Style library.
    * Does not need to terminate if the shared library fails to load.
    * But the exception must be handled when a function is called.
    */
    static
    {   // load shared library from the classpath
        String astylePath = System.getProperty("user.dir")
                            + System.getProperty("file.separator")
                            + System.mapLibraryName("astylej");
        try
        {   System.load(astylePath);
            //~ System.loadLibrary("astyle");
        }
        catch (UnsatisfiedLinkError e)
        {   displayErrorMessage(e.getMessage());
            displayErrorMessage("Cannot load native library " + astylePath);
            displayErrorMessage("The program has terminated!");
            System.exit(1);
        }
    }

    /**
    * Call the AStyleMain function in Artistic Style.
    *
    * @param   textIn  A string containing the source code to be formatted.
    * @return  A String containing the formatted source from Artistic Style.
    */
    public String formatSource(String textIn)
    {   String options = getOptions();
        //~ displayErrorMessage("--------------------\n"
        //~ + options + "\n"
        //~ + "--------------------" );
        String textOut = new String("");
        try
        {   textOut = AStyleMain(textIn, options);
        }
        catch (UnsatisfiedLinkError e)
        {   //~ System.out.println(e.getMessage());
            System.out.println("cannot call function AStyleMain");
        }
        return textOut;
    }

    /**
    * Set fileMode and call the AStyleMain function in Artistic Style.
    *
    * @param   textIn    A string containing the source code to be formatted.
    * @param   fileName  A pointer to the name of the file being formatted.
    * @return  A String containing the formatted source from Artistic Style.
    */
    public String formatSource(String textIn, String fileName)
    {   // set file mode before formatting source
        setFileMode(fileName);
        String textOut = formatSource(textIn);
        return textOut;
    }

    /**
    * Set fileMode and call the AStyleMain function in Artistic Style.
    *
    * @param   textIn       A string containing the source code to be formatted.
    * @param   fileModeArg  A numeric indicator of the file being formatted.
    * @return  A String containing the formatted source from Artistic Style.
    */
    public String formatSource(String textIn, int fileModeArg)
    {   // set file mode before formatting source
        fileMode = fileModeArg;
        String textOut = formatSource(textIn);
        return textOut;
    }

    /**
    *  Call the AStyleGetVersion function in Artistic Style.
    *  @return  A String containing the formatted source from Artistic Style,
    *           or an empty string on error.
    */
    public String getVersion()
    {   String version = new String();
        try
        {   version = AStyleGetVersion();
        }
        catch (UnsatisfiedLinkError e)
        {   //~ System.out.println(e.getMessage());
            System.out.println("cannot call function GetVersion");
        }
        return version;
    }

    /**
    * Calls the GetVersion function in Artistic Style.
    *
    * @return    A String containing the version number of Artistic Style.
    */
    public native String AStyleGetVersion();

    /**
    * Calls the AStyleMain function in Artistic Style.
    *
    * @param    textIn  A string containing the source code to be formatted.
    * @param   options   A string of options to Artistic Style.
    * @return  A String containing the formatted source from Artistic Style.
    */
    private native String AStyleMain(String textIn, String options);

    /**
    * Error handler for messages from Artistic Style.
    * This method is called only if there are errors when AStyleMain is called.
    * This is for debugging and there should be no errors when the calling
    * parameters are correct.
    * Signature: (ILjava/lang/String;)V
    *
    * @param  errorNumber   The error number from Artistic Style.
    * @param  errorMessage  The error message from Artistic Style.
    */
    private void ErrorHandler(int errorNumber, String errorMessage)
    {   displayErrorMessage("astyle error "
                            + String.valueOf(errorNumber)
                            + " - "  + errorMessage);
    }

}   // class AStyleInterface
