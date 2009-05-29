//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//-------------------------------------------------------------------------
// AStyle Break Blocks
//-------------------------------------------------------------------------

TEST(BreakBlocks)
{
	// simple break blocks test
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    fooBar1 = 1;\n"
		"    fooBar2 = 2;\n"
		"    fooBar3 = 3;\n"
		"    if (isFoo2)\n"
		"    {\n"
		"        Bar2();\n"
		"    }\n"
		"    fooBar1 = 1;\n"
		"    fooBar2 = 2;\n"
		"    fooBar3 = 3;\n"
		"}\n";

	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"\n"
		"    fooBar1 = 1;\n"
		"    fooBar2 = 2;\n"
		"    fooBar3 = 3;\n"
		"\n"
		"    if (isFoo2)\n"
		"    {\n"
		"        Bar2();\n"
		"    }\n"
		"\n"
		"    fooBar1 = 1;\n"
		"    fooBar2 = 2;\n"
		"    fooBar3 = 3;\n"
		"}\n";

	char options[] = "break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakBlocksShort)
{
	// simple break blocks short option test
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    fooBar1 = 1;\n"
		"    fooBar2 = 2;\n"
		"    fooBar3 = 3;\n"
		"    if (isFoo2)\n"
		"    {\n"
		"        Bar2();\n"
		"    }\n"
		"    fooBar1 = 1;\n"
		"    fooBar2 = 2;\n"
		"    fooBar3 = 3;\n"
		"}\n";

	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"\n"
		"    fooBar1 = 1;\n"
		"    fooBar2 = 2;\n"
		"    fooBar3 = 3;\n"
		"\n"
		"    if (isFoo2)\n"
		"    {\n"
		"        Bar2();\n"
		"    }\n"
		"\n"
		"    fooBar1 = 1;\n"
		"    fooBar2 = 2;\n"
		"    fooBar3 = 3;\n"
		"}\n";

	char options[] = "-f";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakBlocksWithBrackets)
{
	// break blocks with preceding and following brackets
	// should NOT braek before brackets
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    if (isFoo2)\n"
		"    {\n"
		"        Bar2();\n"
		"    }\n"
		"}\n";

	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"\n"
		"    if (isFoo2)\n"
		"    {\n"
		"        Bar2();\n"
		"    }\n"
		"}\n";

	char options[] = "break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakBlocksWithElse)
{
	// break blocks with 'else' statement
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    else\n"
		"        Bar2();\n"
		"    fooBar1 = 1;\n"
		"    fooBar2 = 2;\n"
		"    fooBar3 = 3;\n"
		"    if (isFoo2)\n"
		"    {\n"
		"        Bar2();\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        Bar2();\n"
		"    }\n"
		"    fooBar1 = 1;\n"
		"    fooBar2 = 2;\n"
		"    fooBar3 = 3;\n"
		"}\n";

	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    else\n"
		"        Bar2();\n"
		"\n"
		"    fooBar1 = 1;\n"
		"    fooBar2 = 2;\n"
		"    fooBar3 = 3;\n"
		"\n"
		"    if (isFoo2)\n"
		"    {\n"
		"        Bar2();\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        Bar2();\n"
		"    }\n"
		"\n"
		"    fooBar1 = 1;\n"
		"    fooBar2 = 2;\n"
		"    fooBar3 = 3;\n"
		"}\n";

	char options[] = "break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakBlocksWithForLoop)
{
	// break blocks with 'for' loops
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar1 = 1;\n"
		"    for (int i=0; i<fooMax; ++i)\n"
		"        bar1++;\n"
		"    fooBar2 = 2;\n"
		"    for (int i=0; i<fooMax; ++i)\n"
		"    {\n"
		"        bar2++;\n"
		"    }\n"
		"    fooBar3 = 3;\n"
		"    for (int i=0; i<fooMax; ++i)\n"
		"        if (isBar)\n"
		"            bar3++;\n"
		"    fooBar4 = 4;\n"
		"    for (int i=0; i<getMax(); ++i)\n"
		"        if (isBar)\n"
		"            bar4++;\n"
		"    fooBar5 = 5;\n"
		"}\n";

	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar1 = 1;\n"
		"\n"
		"    for (int i=0; i<fooMax; ++i)\n"
		"        bar1++;\n"
		"\n"
		"    fooBar2 = 2;\n"
		"\n"
		"    for (int i=0; i<fooMax; ++i)\n"
		"    {\n"
		"        bar2++;\n"
		"    }\n"
		"\n"
		"    fooBar3 = 3;\n"
		"\n"
		"    for (int i=0; i<fooMax; ++i)\n"
		"        if (isBar)\n"
		"            bar3++;\n"
		"\n"
		"    fooBar4 = 4;\n"
		"\n"
		"    for (int i=0; i<getMax(); ++i)\n"
		"        if (isBar)\n"
		"            bar4++;\n"
		"\n"
		"    fooBar5 = 5;\n"
		"}\n";

	char options[] = "break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakBlocksWithSwitch)
{
	// break blocks with 'switch'
	// switch is broken but not the case statements
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    int fooBar = 0;\n"
		"    switch (test)\n"
		"    {\n"
		"    case 1:\n"
		"        fooBar = 1;\n"
		"        break;\n"
		"    case 2: {\n"
		"        fooBar = 2;\n"
		"    }\n"
		"    break;\n"
		"    default:\n"
		"        break;\n"
		"    }\n"
		"    int bar = true;\n"
		"}\n";

	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    int fooBar = 0;\n"
		"\n"
		"    switch (test)\n"
		"    {\n"
		"    case 1:\n"
		"        fooBar = 1;\n"
		"        break;\n"
		"    case 2: {\n"
		"        fooBar = 2;\n"
		"    }\n"
		"    break;\n"
		"    default:\n"
		"        break;\n"
		"    }\n"
		"\n"
		"    int bar = true;\n"
		"}\n";

	char options[] = "break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakBlocksWithPreprocessor)
{
	// do NOT break blocks at a preprocessor directive
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"#ifdef fooDef\n"
		"    if (isBar1)\n"
		"        fooBar1();\n"
		"#else\n"
		"    if (isBar2)\n"
		"        fooBar2();\n"
		"#endif\n"
		"    if (isBar3)\n"
		"        fooBar3();\n"
		"}\n";

	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"#ifdef fooDef\n"
		"\n"
		"    if (isBar1)\n"
		"        fooBar1();\n"
		"\n"
		"#else\n"
		"\n"
		"    if (isBar2)\n"
		"        fooBar2();\n"
		"\n"
		"#endif\n"
		"\n"
		"    if (isBar3)\n"
		"        fooBar3();\n"
		"}\n";

	char options[] = "break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakBlocksWithComment1)
{
	// blocks with comments are correctly broken
	// and should not be changed
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar1 = 1;\n"
		"\n"
		"    // comment one\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    else\n"
		"        Bar2();\n"
		"\n"
		"    fooBar2 = 2;\n"
		"\n"
		"    /* comment two */\n"
		"    if (isFoo2) {\n"
		"        Bar3();\n"
		"    } else {\n"
		"        Bar4();\n"
		"    }\n"
		"}\n";

	char options[] = "break-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakBlocksWithComment2)
{
	// blocks with comments beginning the line
	// should be broken
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar1 = 1;\n"
		"    // comment one\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    else\n"
		"        Bar2();\n"
		"    fooBar2 = 2;\n"
		"    /* comment two */\n"
		"    if (isFoo2) {\n"
		"        Bar3();\n"
		"    } else {\n"
		"        Bar4();\n"
		"    }\n"
		"}\n";

	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar1 = 1;\n"
		"\n"
		"    // comment one\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    else\n"
		"        Bar2();\n"
		"\n"
		"    fooBar2 = 2;\n"
		"\n"
		"    /* comment two */\n"
		"    if (isFoo2) {\n"
		"        Bar3();\n"
		"    } else {\n"
		"        Bar4();\n"
		"    }\n"
		"}\n";

	char options[] = "break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakBlocksWithComment3)
{
	// blocks with comments not beginning the line
	// should be broken
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar1 = 1;  // comment one\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    else\n"
		"        Bar2();\n"
		"    fooBar2 = 2;  /* comment two */\n"
		"    if (isFoo2) {\n"
		"        Bar3();\n"
		"    } else {\n"
		"        Bar4();\n"
		"    }\n"
		"    fooBar3 = 3;\n"
		"}\n";

	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar1 = 1;  // comment one\n"
		"\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    else\n"
		"        Bar2();\n"
		"\n"
		"    fooBar2 = 2;  /* comment two */\n"
		"\n"
		"    if (isFoo2) {\n"
		"        Bar3();\n"
		"    } else {\n"
		"        Bar4();\n"
		"    }\n"
		"\n"
		"    fooBar3 = 3;\n"
		"}\n";

	char options[] = "break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakBlocksWithComment4)
{
	// blocks with comments should be broken
	// leaving comments with the blocks
	// but closing headers should NOT be broken
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar1 = 1;\n"
		"    // comment one\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    // comment two\n"
		"    else\n"
		"        Bar2();\n"
		"    fooBar2 = 2;\n"
		"    /* comment three */\n"
		"    if (isFoo3)\n"
		"    {\n"
		"        Bar3();\n"
		"    }\n"
		"    /* comment four */\n"
		"    else\n"
		"        Bar4();\n"
		"    fooBar3 = 3;\n"
		"}\n";

	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar1 = 1;\n"
		"\n"
		"    // comment one\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    // comment two\n"
		"    else\n"
		"        Bar2();\n"
		"\n"
		"    fooBar2 = 2;\n"
		"\n"
		"    /* comment three */\n"
		"    if (isFoo3)\n"
		"    {\n"
		"        Bar3();\n"
		"    }\n"
		"    /* comment four */\n"
		"    else\n"
		"        Bar4();\n"
		"\n"
		"    fooBar3 = 3;\n"
		"}\n";

	char options[] = "break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakBlocksWithComment5)
{
	// blocks with comments should be broken
	// leaving comments with the blocks
	// test mixing comments and line comments
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar();\n"
		"    /* comment1 */\n"
		"    // comment2\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"    fooBar();\n"
		"    /* comment1 */\n"
		"    // comment2\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar();\n"
		"\n"
		"    /* comment1 */\n"
		"    // comment2\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"    fooBar();\n"
		"\n"
		"    /* comment1 */\n"
		"    // comment2\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"}\n";
	char options[] = "break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakBlocksSans1)
{
	// don't break bocks for preDefinitionHeaders (namespace, class...)
	// don't break bocks for access modifiers (public, private, protected)
	//     when keep-one-line-statements is used.
	char text[] =
		"\nnamespace astyle\n"
		"{\n"
		"class ASSourceIterator\n"
		"{\n"
		"public:\n"
		"    ASSourceIterator() {}\n"
		"};\n"
		"\n"
		"class ASResource\n"
		"{\n"
		"public:\n"
		"    ASResource() {}\n"
		"};\n"
		"}\n";
	char options[] = "break-blocks, keep-one-line-statements, keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakBlocksSans2)
{
	// don't break blocks for C# 'get' and 'set' or 'add' and 'remove'
	char text[] =
		"\npublic class TextEditor : ITextEditor\n"
		"{\n"
		"    public event KeyEventHandler KeyPress {\n"
		"        add { textArea.KeyEventHandler += value; }\n"
		"        remove { textArea.KeyEventHandler -= value; }\n"
		"    }\n"
		"\n"
		"    public IndentStyle IndentStyle {\n"
		"        get { return textEditorControl.IndentStyle; }\n"
		"        set { SetIndentStyle(value); }\n"
		"    }\n"
		"}\n";
	char options[] = "break-blocks, keep-one-line-blocks, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


//-------------------------------------------------------------------------
// AStyle Break All Blocks
//-------------------------------------------------------------------------

TEST(BreakAllBlocks)
{
	// simple break all blocks test
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    else\n"
		"        Bar2();\n"
		"    fooBar1 = 1;\n"
		"    if (isFoo2) {\n"
		"        Bar1();\n"
		"    }\n"
		"    else {\n"
		"        Bar2();\n"
		"    }\n"
		"    fooBar2 = 2;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"\n"
		"    else\n"
		"        Bar2();\n"
		"\n"
		"    fooBar1 = 1;\n"
		"\n"
		"    if (isFoo2) {\n"
		"        Bar1();\n"
		"    }\n"
		"\n"
		"    else {\n"
		"        Bar2();\n"
		"    }\n"
		"\n"
		"    fooBar2 = 2;\n"
		"}\n";
	char options[] = "break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakAllBlocksShort)
{
	// simple break all blocks short option test
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    else\n"
		"        Bar2();\n"
		"    fooBar1 = 1;\n"
		"    if (isFoo2) {\n"
		"        Bar1();\n"
		"    }\n"
		"    else {\n"
		"        Bar2();\n"
		"    }\n"
		"    fooBar2 = 2;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"\n"
		"    else\n"
		"        Bar2();\n"
		"\n"
		"    fooBar1 = 1;\n"
		"\n"
		"    if (isFoo2) {\n"
		"        Bar1();\n"
		"    }\n"
		"\n"
		"    else {\n"
		"        Bar2();\n"
		"    }\n"
		"\n"
		"    fooBar2 = 2;\n"
		"}\n";
	char options[] = "-F";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakAllBlocksBreakBrackets)
{
	// test break all blocks with break brackets
	char textIn[] =
		"\nvoid foo() {\n"
		"    bar1();\n"
		"    if (isBar) {  // comment\n"
		"        bar2();\n"
		"        return;\n"
		"    }\n"
		"    bar3();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1();\n"
		"\n"
		"    if (isBar)    // comment\n"
		"    {\n"
		"        bar2();\n"
		"        return;\n"
		"    }\n"
		"\n"
		"    bar3();\n"
		"}\n";
	char options[] = "break-blocks=all, brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakAllBlocksAttachBrackets)
{
	// test break all blocks with attach brackets
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1();\n"
		"    if (isBar)   // comment\n"
		"    {\n"
		"        bar2();\n"
		"        return;\n"
		"    }\n"
		"    bar3();\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"    bar1();\n"
		"\n"
		"    if (isBar) { // comment\n"
		"        bar2();\n"
		"        return;\n"
		"    }\n"
		"\n"
		"    bar3();\n"
		"}\n";
	char options[] = "break-blocks=all, brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakAllBlocksWithDoWhile)
{
	// break all blocks with do-while
	// closing while should NOT be broken from the block
	// but the following statement should be broken
	char textIn[] =
		"void Foo()\n"
		"{\n"
		"    do\n"
		"    {\n"
		"        bar1();\n"
		"    }\n"
		"    while (false);\n"
		"    bar2();\n"
		"}\n";
	char text[] =
		"void Foo()\n"
		"{\n"
		"    do\n"
		"    {\n"
		"        bar1();\n"
		"    }\n"
		"    while (false);\n"
		"\n"
		"    bar2();\n"
		"}\n";
	char options[] = "break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakAllBlocksWithComment1)
{
	// blocks with comments are correctly broken
	// and should not be changed
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    // comment\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"\n"
		"    // comment\n"
		"    else\n"
		"        Bar1();\n"
		"\n"
		"    /* comment */\n"
		"    if (isFoo2) {\n"
		"        Bar2();\n"
		"    }\n"
		"\n"
		"    /* comment */\n"
		"    else {\n"
		"        Bar2();\n"
		"    }\n"
		"}\n";
	char options[] = "break-blocks=all";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakAllBlocksWithComment2)
{
	// blocks with comments not beginning the line
	// should be broken
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar0 = 0;\n"
		"    if (isFoo1) {\n"
		"        Bar1();\n"
		"    }            // comment one\n"
		"    else\n"
		"        Bar2();\n"
		"    fooBar1 = 1;\n"
		"    if (isFoo2) {\n"
		"        Bar1();\n"
		"    }            /* comment two */\n"
		"    else {\n"
		"        Bar2();\n"
		"    }\n"
		"    fooBar2 = 2;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar0 = 0;\n"
		"\n"
		"    if (isFoo1) {\n"
		"        Bar1();\n"
		"    }            // comment one\n"
		"\n"
		"    else\n"
		"        Bar2();\n"
		"\n"
		"    fooBar1 = 1;\n"
		"\n"
		"    if (isFoo2) {\n"
		"        Bar1();\n"
		"    }            /* comment two */\n"
		"\n"
		"    else {\n"
		"        Bar2();\n"
		"    }\n"
		"\n"
		"    fooBar2 = 2;\n"
		"}\n";
	char options[] = "break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakAllBlocksWithComment3)
{
	// blocks with comments should be broken
	// leaving comments with the blocks
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    // comment\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"    // comment\n"
		"    else\n"
		"        Bar1();\n"
		"    /* comment */\n"
		"    if (isFoo2) {\n"
		"        Bar2();\n"
		"    }\n"
		"    /* comment */\n"
		"    else {\n"
		"        Bar2();\n"
		"    }\n"
		"}\n";

	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    // comment\n"
		"    if (isFoo1)\n"
		"        Bar1();\n"
		"\n"
		"    // comment\n"
		"    else\n"
		"        Bar1();\n"
		"\n"
		"    /* comment */\n"
		"    if (isFoo2) {\n"
		"        Bar2();\n"
		"    }\n"
		"\n"
		"    /* comment */\n"
		"    else {\n"
		"        Bar2();\n"
		"    }\n"
		"}\n";
	char options[] = "break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakAllBlocksAfterComment1)
{
	// closing block should break after a comment
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1) {\n"
		"        Bar1();\n"
		"        // comment\n"
		"    } else {\n"
		"        Bar2();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1) {\n"
		"        Bar1();\n"
		"        // comment\n"
		"\n"
		"    } else {\n"
		"        Bar2();\n"
		"    }\n"
		"}\n";
	char options[] = "break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakAllBlocksAfterComment2)
{
	// closing block should break after a comment
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1) {\n"
		"        Bar1();\n"
		"        // comment\n"
		"    } else {\n"
		"        Bar2();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1) {\n"
		"        Bar1();\n"
		"        // comment\n"
		"\n"
		"    } else {\n"
		"        Bar2();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux, break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakAllBlocksAfterComment3)
{
	// closing block should break after a comment
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1)\n {\n"
		"        Bar1();\n"
		"        // comment\n"
		"    } else {\n"
		"        Bar2();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"    {\n"
		"        Bar1();\n"
		"        // comment\n"
		"    }\n"
		"\n"
		"    else\n"
		"    {\n"
		"        Bar2();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break, break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Pad Operator
//-------------------------------------------------------------------------

TEST(PadOperator)
{
	// test pad operators
	// all operators should be tested
	// test sequence is the same as ASResource::buildOperators
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    a+=b;\n"
		"    a-=b;\n"
		"    a*=b;\n"
		"    a/=b;\n"
		"    a%=b;\n"
		"    a|=b;\n"
		"    a&=b;\n"
		"    a^=b;\n"
		"    a==b;\n"
		"    a--;\n"       // should not pad
		"    a++;\n"       // should not pad
		"    --b;\n"       // should not pad
		"    ++b;\n"       // should not pad
		"    a!=b;\n"
		"    a>=b;\n"
		"    a>>>=b;\n"
		"    a>>=b;\n"
		"    a>>>b;\n"
		"    a>>b;\n"
		"    a<=b;\n"
		"    a<<<=b;\n"
		"    a<<=b;\n"
		"    a<<<b;\n"
		"    a<<b;\n"
		"    a??b;\n"
		"    a=>b;\n"
		"    a<?b;\n"
		"    a>?b;\n"
		"    a->b;\n"      // should not pad
		"    a&&b;\n"
		"    a||b;\n"
		"    a::b;\n"      // should not pad
		"    a+b;\n"
		"    a-b;\n"
		"    x=a*b;\n"     // without the equal sign it is a pointer
		"    a/b;\n"
		"    a%b;\n"
		"    x=a?b:c;\n"   // without the equal sign ':' is a label
		"    a=b;\n"
		"    a<b;\n"
		"    a>b;\n"
		"    a^b;\n"
		"    a|b;\n"
		"    x=a&b;\n"     // without the equal sign it is a reference
		"    a^b;\n"
		"}\n";             // 'operator' and 'return' are not tested
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    a += b;\n"
		"    a -= b;\n"
		"    a *= b;\n"
		"    a /= b;\n"
		"    a %= b;\n"
		"    a |= b;\n"
		"    a &= b;\n"
		"    a ^= b;\n"
		"    a == b;\n"
		"    a--;\n"         // should not pad
		"    a++;\n"         // should not pad
		"    --b;\n"         // should not pad
		"    ++b;\n"         // should not pad
		"    a != b;\n"
		"    a >= b;\n"
		"    a >>>= b;\n"
		"    a >>= b;\n"
		"    a >>> b;\n"
		"    a >> b;\n"
		"    a <= b;\n"
		"    a <<<= b;\n"
		"    a <<= b;\n"
		"    a <<< b;\n"
		"    a << b;\n"
		"    a ?? b;\n"
		"    a => b;\n"
		"    a <? b;\n"
		"    a >? b;\n"
		"    a->b;\n"        // should not pad
		"    a && b;\n"
		"    a || b;\n"
		"    a::b;\n"        // should not pad
		"    a + b;\n"
		"    a - b;\n"
		"    x = a * b;\n"   // without the equal sign it is a pointer
		"    a / b;\n"
		"    a % b;\n"
		"    x = a ? b : c;\n" // without the equal sign ':' is a label
		"    a = b;\n"
		"    a < b;\n"
		"    a > b;\n"
		"    a ^ b;\n"
		"    a | b;\n"
		"    x = a & b;\n"   // without the equal sign it is a reference
		"    a ^ b;\n"
		"}\n";               // 'operator' and 'return' are not tested
	char options[] = "pad-oper";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadOperatorShort)
{
	// test pad operators short option
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    x=a+b-((c*d)/e);\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    x = a + b - ((c * d) / e);\n"
		"}\n";
	char options[] = "-p";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadOperatorMisc1)
{
	// more pad operators tests
	char textIn[] =
		"\nvoid foo(pdfColour& a, pdfColour &b)\n"
		"{\n"
		"    xxx=new yyy(zzz,_(\"XXX\"),_T(\"YYY\"));\n"
		"\n"
		"    while (*p=='x'||*p=='y')\n"
		"        ++p;\n"
		"\n"
		"    bool operator== (fooBar& a, fooBar &b);\n"
		"    bool operator== (fooBar* a, fooBar *b);\n"
		"\n"
		"    if (*sl==s) *sl=t;\n"
		"\n"
		"    setProperty(\"md5 \"+md5Count);\n"
		"\n"
		"    return (i-m+1);\n"
		"    *end=endAlt;\n"
		"    return &end;\n"
		"}\n";
	char text[] =
		"\nvoid foo(pdfColour& a, pdfColour &b)\n"
		"{\n"
		"    xxx = new yyy(zzz, _(\"XXX\"), _T(\"YYY\"));\n"
		"\n"
		"    while (*p == 'x' || *p == 'y')\n"
		"        ++p;\n"
		"\n"
		"    bool operator== (fooBar& a, fooBar &b);\n"
		"    bool operator== (fooBar* a, fooBar *b);\n"
		"\n"
		"    if (*sl == s) *sl = t;\n"
		"\n"
		"    setProperty(\"md5 \" + md5Count);\n"
		"\n"
		"    return (i - m + 1);\n"
		"    *end = endAlt;\n"
		"    return &end;\n"
		"}\n";
	char options[] = "pad-oper";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadOperatorMisc2)
{
	// test C# ? operator and nullable types
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    int? bar;\n"
		"    (bar==1)?\"topic\":\"topics\";\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    int? bar;\n"
		"    (bar == 1) ? \"topic\" : \"topics\";\n"
		"}\n";
	char options[] = "pad-oper, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadOperatorSans1)
{
	// test pad operators
	// these operators should NOT be padded
	char text[] =
		"\nclass FooClass\n"
		"{\n"
		"public:\n"
		"    ~Foo();\n"
		"    ~Foo() {\n"
		"    }\n"
		"    ~Foo();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar[] = \"one\",\n"
		"                \"two\";\n"
		"    }\n"
		"\n"
		"    if (!(x == y))\n"
		"        bar();\n"
		"\n"
		"    double x(-2.0);\n"
		"\n"
		"    x->y = 2;\n"
		"    x = (-2 * -1);\n"
		"    x = -2 + -1;\n"
		"\n"
		"    x.*y = z;\n"
		"    x->*y = z;\n"
		"\n"
		"    x = ~y;\n"
		"\n"
		"    return +1;\n"
		"    return (+1);\n"
		"    return -1;\n"
		"    return (-1);\n"
		"}\n";
	char options[] = "pad-oper";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadOperatorSans2)
{
	// test pad operators
	// overloaded operators should NOT be padded
	char text[] =
		"\nclass Foo {\n"
		"    Foo::operator= () {}\n"
		"    Foo::operator> () {}\n"
		"    Foo::operator>= () {}\n"
		"}\n";
	char options[] = "pad-oper";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadOperatorSans3)
{
	// test pad operators
	// the Java generic <?> should NOT be padded
	char text[] =
		"\npublic Class<?> Foo(Class<?> _class)\n"
		"{\n"
		"    return bar;\n"
		"}\n";
	char options[] = "pad-oper, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadOperatorCommaSemiColon)
{
	// semi-colons should ALWAYS be padded
	// commas should be padded with pad-oper, but not in arrays
	char textIn[] =
		"\nvoid foo(int bar1,int bar2,int bar3)\n"
		"{\n"
		"    for (i=0,j=0;i<10;i++)\n"
		"        xxx+=i;\n"
		"}\n"
		"\n"
		"static bool[,] set = {\n"
		"    {T,T,x,T, x,T,x,T, T,T,x,T, T,T,T,x},\n"
		"    {x,x,x,x, x,x,x,x, x,x,x,T, T,T,T,x},\n"
		"    {T,T,x,T, x,T,x,T, T,T,x,T, T,T,T,x},\n"
		"    {x,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T}\n"
		"};\n";
	char text[] =
		"\nvoid foo(int bar1, int bar2, int bar3)\n"
		"{\n"
		"    for (i = 0, j = 0; i < 10; i++)\n"
		"        xxx += i;\n"
		"}\n"
		"\n"
		"static bool[,] set = {\n"
		"    {T, T, x, T, x, T, x, T, T, T, x, T, T, T, T, x},\n"
		"    {x, x, x, x, x, x, x, x, x, x, x, T, T, T, T, x},\n"
		"    {T, T, x, T, x, T, x, T, T, T, x, T, T, T, T, x},\n"
		"    {x, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T}\n"
		"};\n";
	char options[] = "pad-oper";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadOperatorComments)
{
	// EOL comments remain in the same column if possible
	// moved comments retain the original spacing
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    c=a+b;      // comment ok\n"
		"    g=d+e+f;    // comment must move\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    c = a + b;  // comment ok\n"
		"    g = d + e + f; // comment must move\n"
		"}\n";
	char options[] = "pad-oper";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Pad Paren
//-------------------------------------------------------------------------

TEST(PadParen)
{
	// test pad parens
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo(a, b))\n"
		"        bar(a, b);\n"
		"}\n";
	char text[] =
		"\nvoid foo ( bool isFoo )\n"
		"{\n"
		"    if ( isFoo ( a, b ) )\n"
		"        bar ( a, b );\n"
		"}\n";
	char options[] = "pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadParenShort)
{
	// test pad parens short option
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo(a, b))\n"
		"        bar(a, b);\n"
		"}\n";
	char text[] =
		"\nvoid foo ( bool isFoo )\n"
		"{\n"
		"    if ( isFoo ( a, b ) )\n"
		"        bar ( a, b );\n"
		"}\n";
	char options[] = "-P";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadParenComments)
{
	// EOL comments remain in the same column if possible
	// moved comments retain the original spacing
	char textIn[] =
		"\nvoid foo(bool isFoo)    // comment ok\n"
		"{\n"
		"    if (isFoo(a, b))    // comment must move\n"
		"        bar(a, b);        // comment ok\n"
		"}\n";
	char text[] =
		"\nvoid foo ( bool isFoo ) // comment ok\n"
		"{\n"
		"    if ( isFoo ( a, b ) ) // comment must move\n"
		"        bar ( a, b );     // comment ok\n"
		"}\n";
	char options[] = "pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Pad Paren Out
//-------------------------------------------------------------------------

TEST(PadParenOut)
{
	// test pad parens out
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo(a, b))\n"
		"        bar(a, b);\n"
		"}\n";
	char text[] =
		"\nvoid foo (bool isFoo)\n"
		"{\n"
		"    if (isFoo (a, b) )\n"
		"        bar (a, b);\n"
		"}\n";
	char options[] = "pad-paren-out";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadParenOutShort)
{
	// test pad parens out short option
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo(a, b))\n"
		"        bar(a, b);\n"
		"}\n";
	char text[] =
		"\nvoid foo (bool isFoo)\n"
		"{\n"
		"    if (isFoo (a, b) )\n"
		"        bar (a, b);\n"
		"}\n";
	char options[] = "-d";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadParenOutComments)
{
	// EOL comments remain in the same column if possible
	// moved comments retain the original spacing
	char textIn[] =
		"\nvoid foo(bool isFoo)  // comment ok\n"
		"{\n"
		"    if (isFoo(a, b))  // comment must move\n"
		"        bar(a, b);      // comment ok\n"
		"}\n";
	char text[] =
		"\nvoid foo (bool isFoo) // comment ok\n"
		"{\n"
		"    if (isFoo (a, b) ) // comment must move\n"
		"        bar (a, b);     // comment ok\n"
		"}\n";
	char options[] = "pad-paren-out";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Pad Paren In
//-------------------------------------------------------------------------

TEST(PadParenIn)
{
	// test pad parens in
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo(a, b))\n"
		"        bar(a, b);\n"
		"}\n";
	char text[] =
		"\nvoid foo( bool isFoo )\n"
		"{\n"
		"    if ( isFoo( a, b ) )\n"
		"        bar( a, b );\n"
		"}\n";
	char options[] = "pad-paren-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadParenInShort)
{
	// test pad parens in short option
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo(a, b))\n"
		"        bar(a, b);\n"
		"}\n";
	char text[] =
		"\nvoid foo( bool isFoo )\n"
		"{\n"
		"    if ( isFoo( a, b ) )\n"
		"        bar( a, b );\n"
		"}\n";
	char options[] = "-D";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadParenInComments)
{
	// EOL comments remain in the same column if possible
	// moved comments retain the original spacing
	char textIn[] =
		"\nvoid foo(bool isFoo)   // comment ok\n"
		"{\n"
		"    if (isFoo(a, b))  // comment must move\n"
		"        bar(a, b);      // comment ok\n"
		"}\n";
	char text[] =
		"\nvoid foo( bool isFoo ) // comment ok\n"
		"{\n"
		"    if ( isFoo( a, b ) ) // comment must move\n"
		"        bar( a, b );    // comment ok\n"
		"}\n";
	char options[] = "pad-paren-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Pad Header
//-------------------------------------------------------------------------

TEST(PadHeader)
{
	// test pad header
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(isFoo(a, b))\n"
		"        bar(a, b);\n"
		"\n"
		"    while(a>b)\n"
		"        fooBar(a, b);\n"
		"\n"
		"    nonHeader(a, b);\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo(a, b))\n"
		"        bar(a, b);\n"
		"\n"
		"    while (a>b)\n"
		"        fooBar(a, b);\n"
		"\n"
		"    nonHeader(a, b);\n"
		"}\n";
	char options[] = "pad-header";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadHeaderShort)
{
	// test header short option
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(isFoo(a, b))\n"
		"        bar(a, b);\n"
		"\n"
		"    while(a>b)\n"
		"        fooBar(a, b);\n"
		"\n"
		"    nonHeader(a, b);\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo(a, b))\n"
		"        bar(a, b);\n"
		"\n"
		"    while (a>b)\n"
		"        fooBar(a, b);\n"
		"\n"
		"    nonHeader(a, b);\n"
		"}\n";
	char options[] = "-H";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadHeaderSans)
{	// test without pad header
	// headers should remain unchanged
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(isFoo(a, b))\n"
		"        bar(a, b);\n"
		"\n"
		"    while (a>b)\n"
		"        fooBar(a, b);\n"
		"\n"
		"    nonHeader1(a, b);\n"
		"\n"
		"    nonHeader2 (a, b);\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(isFoo(a, b))\n"
		"        bar(a, b);\n"
		"\n"
		"    while (a>b)\n"
		"        fooBar(a, b);\n"
		"\n"
		"    nonHeader1(a, b);\n"
		"\n"
		"    nonHeader2 (a, b);\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
TEST(PadHeaderUnpadParen)
{	// test pad header with unpad paren
	// headers should be padded, others should not
	// will remove extra padding from headers
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(isFoo(a, b))\n"
		"        bar(a, b);\n"
		"\n"
		"    while  (a>b)\n"
		"        fooBar(a, b);\n"
		"\n"
		"    nonHeader1(a, b);\n"
		"\n"
		"    nonHeader2 (a, b);\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo(a, b))\n"
		"        bar(a, b);\n"
		"\n"
		"    while (a>b)\n"
		"        fooBar(a, b);\n"
		"\n"
		"    nonHeader1(a, b);\n"
		"\n"
		"    nonHeader2(a, b);\n"
		"}\n";
	char options[] = "pad-header, unpad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PadHeaderComments)
{
	// EOL comments remain in the same column if possible
	// moved comments retain the original spacing
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(isFoo(a, b)) // comment must move\n"
		"        bar(a, b);\n"
		"\n"
		"    while(a>b)      // comment ok\n"
		"        fooBar(a, b);\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo(a, b)) // comment must move\n"
		"        bar(a, b);\n"
		"\n"
		"    while (a>b)     // comment ok\n"
		"        fooBar(a, b);\n"
		"}\n";
	char options[] = "pad-header";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Unpad Paren
//-------------------------------------------------------------------------

TEST(UnpadParen)
{
	// test unpad parens
	char textIn[] =
		"\nvoid foo ( bool isFoo )\n"
		"{\n"
		"    if ( isFoo ( a, b ) )\n"
		"        bar ( a, b );\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if(isFoo(a, b))\n"
		"        bar(a, b);\n"
		"}\n";
	char options[] = "unpad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(UnpadParenShort)
{
	// test unpad parens short option
	char textIn[] =
		"\nvoid foo ( bool isFoo )\n"
		"{\n"
		"    if ( isFoo ( a, b ) )\n"
		"        bar ( a, b );\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if(isFoo(a, b))\n"
		"        bar(a, b);\n"
		"}\n";
	char options[] = "-U";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(UnpadParenComments)
{
	// EOL comments ALWAYS remain in the same column
	char textIn[] =
		"\nvoid foo ( bool isFoo ) // comment ok\n"
		"{\n"
		"    if ( isFoo ( a, b ) ) // comment ok\n"
		"        bar ( a, b );     // comment ok\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)    // comment ok\n"
		"{\n"
		"    if(isFoo(a, b))       // comment ok\n"
		"        bar(a, b);        // comment ok\n"
		"}\n";
	char options[] = "unpad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(UnpadParenPadParen)
{
	// test unpad parens with pad parens
	// should be padded but will remove extra padding
	char textIn[] =
		"\nvoid foo ( bool isFoo )\n"
		"{\n"
		"    if  (  isFoo  ( a, b )  )\n"
		"        bar ( a, b );\n"
		"    if (isFoo(a, b))\n"
		"        bar(a, b);\n"
		"}\n";
	char text[] =
		"\nvoid foo ( bool isFoo )\n"
		"{\n"
		"    if ( isFoo ( a, b ) )\n"
		"        bar ( a, b );\n"
		"    if ( isFoo ( a, b ) )\n"
		"        bar ( a, b );\n"
		"}\n";
	char options[] = "unpad-paren, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(UnpadParenPadParenOut)
{
	// test unpad parens with pad parens out
	// should be padded outside but will remove extra padding
	char textIn[] =
		"\nvoid foo( bool isFoo )\n"
		"{\n"
		"    if  (  isFoo  ( a, b )  )\n"
		"        bar ( a, b );\n"
		"    if (isFoo(a, b))\n"
		"        bar(a, b);\n"
		"}\n";
	char text[] =
		"\nvoid foo (bool isFoo)\n"
		"{\n"
		"    if (isFoo (a, b))\n"
		"        bar (a, b);\n"
		"    if (isFoo (a, b))\n"
		"        bar (a, b);\n"
		"}\n";
	char options[] = "unpad-paren, pad-paren-out";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(UnpadParenPadIn)
{
	// test unpad parens with pad parens in
	// should be padded inside but will remove extra padding
	char textIn[] =
		"\nvoid foo (bool isFoo)\n"
		"{\n"
		"    if (  isFoo (  a, b  )  )\n"
		"        bar ( a, b );\n"
		"    if (isFoo(a, b))\n"
		"        bar(a, b);\n"
		"}\n";
	char text[] =
		"\nvoid foo( bool isFoo )\n"
		"{\n"
		"    if( isFoo( a, b ) )\n"
		"        bar( a, b );\n"
		"    if( isFoo( a, b ) )\n"
		"        bar( a, b );\n"
		"}\n";
	char options[] = "unpad-paren, pad-paren-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Delete Empty Lines
//-------------------------------------------------------------------------

TEST(DeleteEmptyLines)
{
	// test delete empty lines
	char textIn[] =
		"\nclass fooClass\n"
		"{\n"
		"\n"
		"public:\n"
		"\n"
		"    int foo1;\n"
		"\n"
		"    int foo2;\n"
		"\n"
		"    fooClass() {\n"
		"\n"
		"        int foo1 = 0;\n"
		"\n"
		"\n"
		"        int foo2 = 0;\n"
		"\n"
		"    }\n"
		"\n"
		"};\n"
		"\n"
		"void fooClass::fooBar()\n"
		"{\n"
		"\n"
		"    foo1 = 1;\n"
		"\n"
		"    foo2 = 2;\n"
		"\n"
		"}\n";
	char text[] =
		"\nclass fooClass\n"
		"{\n"
		"\n"
		"public:\n"
		"\n"
		"    int foo1;\n"
		"\n"
		"    int foo2;\n"
		"\n"
		"    fooClass() {\n"
		"        int foo1 = 0;\n"
		"        int foo2 = 0;\n"
		"    }\n"
		"\n"
		"};\n"
		"\n"
		"void fooClass::fooBar()\n"
		"{\n"
		"    foo1 = 1;\n"
		"    foo2 = 2;\n"
		"}\n";
	char options[] = "delete-empty-lines";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(DeleteEmptyLinesShort)
{
	// test delete empty lines
	char textIn[] =
		"\nclass fooClass\n"
		"{\n"
		"\n"
		"public:\n"
		"\n"
		"    int foo1;\n"
		"\n"
		"    int foo2;\n"
		"\n"
		"    fooClass() {\n"
		"\n"
		"        int foo1 = 0;\n"
		"\n"
		"\n"
		"        int foo2 = 0;\n"
		"\n"
		"    }\n"
		"\n"
		"};\n"
		"\n"
		"void fooClass::fooBar()\n"
		"{\n"
		"\n"
		"    foo1 = 1;\n"
		"\n"
		"    foo2 = 2;\n"
		"\n"
		"}\n";
	char text[] =
		"\nclass fooClass\n"
		"{\n"
		"\n"
		"public:\n"
		"\n"
		"    int foo1;\n"
		"\n"
		"    int foo2;\n"
		"\n"
		"    fooClass() {\n"
		"        int foo1 = 0;\n"
		"        int foo2 = 0;\n"
		"    }\n"
		"\n"
		"};\n"
		"\n"
		"void fooClass::fooBar()\n"
		"{\n"
		"    foo1 = 1;\n"
		"    foo2 = 2;\n"
		"}\n";
	char options[] = "-x";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(DeleteEmptyLinesBreakBlocks)
{
	// test delete empty lines, with break blocks
	// the empty lines created by break blocks should NOT be deleted
	char textIn[] =
		"\nvoid Foo(bool fooBar)\n"
		"{\n"
		"    bar1();\n"
		"\n"
		"    // the above empty line should not be deleted\n"
		"    if (fooBar)\n"
		"    {\n"
		"        bar2();\n"
		"    }\n"
		"\n"
		"    // the above empty line should be deleted\n"
		"    else\n"
		"    {\n"
		"        bar3();\n"
		"    }\n"
		"\n"
		"    bar4();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool fooBar)\n"
		"{\n"
		"    bar1();\n"
		"\n"
		"    // the above empty line should not be deleted\n"
		"    if (fooBar)\n"
		"    {\n"
		"        bar2();\n"
		"    }\n"
		"    // the above empty line should be deleted\n"
		"    else\n"
		"    {\n"
		"        bar3();\n"
		"    }\n"
		"\n"
		"    bar4();\n"
		"}\n";
	char options[] = "delete-empty-lines, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(DeleteEmptyLinesBreakBlocksAll)
{
	// test delete empty lines, with break blocks
	// the empty lines created by break all blocks should NOT be deleted
	char text[] =
		"\nvoid Foo(bool fooBar)\n"
		"{\n"
		"    bar1();\n"
		"\n"
		"    // the above empty line should not be deleted\n"
		"    if (fooBar)\n"
		"    {\n"
		"        bar2();\n"
		"    }\n"
		"\n"
		"    // the above empty line should not be deleted\n"
		"    else\n"
		"    {\n"
		"        bar3();\n"
		"    }\n"
		"\n"
		"    bar4();\n"
		"}\n";
	char options[] = "delete-empty-lines, break-blocks=all";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(DeleteEmptyLinesBreakBlocksComment1)
{
	// delete empty lines with break blocks
	// should not delete lines between comments
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    bar1();\n"
		"    // comment1\n"
		"\n"
		"    // comment2\n"
		"    if (isFoo)\n"
		"        bar2();\n"
		"\n"
		"    bar3();\n"
		"    /* comment3 */\n"
		"\n"
		"    /* comment4 */\n"
		"    if (isFoo)\n"
		"        bar4();\n"
		"}\n";
	char options[] = "delete-empty-lines, break-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(DeleteEmptyLinesBreakBlocksComment2)
{
	// delete empty lines with break blocks
	// test mixing comments and line comments
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar();\n"
		"    /* comment1 */\n"
		"    // comment2\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"    fooBar();\n"
		"    /* comment1 */\n"
		"    // comment2\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    fooBar();\n"
		"\n"
		"    /* comment1 */\n"
		"    // comment2\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"    fooBar();\n"
		"\n"
		"    /* comment1 */\n"
		"    // comment2\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"}\n";
	char options[] = "delete-empty-lines, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Fill Empty Lines
//-------------------------------------------------------------------------

TEST(FillEmptyLines)
{
	// test fill empty lines
	char textIn[] =
		"\nvoid foo1(bool isFoo)\n"
		"{\n"
		"    a = 1;\n"
		"\n"
		"    if (isFoo)\n"
		"        b = 2;\n"
		"\n"
		"    c = 3;\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo)\n"
		"{\n"
		"    a = 1;\n"
		"    \n"
		"    if (isFoo)\n"
		"        b = 2;\n"
		"        \n"
		"    c = 3;\n"
		"}\n";
	char options[] = "fill-empty-lines";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(FillEmptyLinesShort)
{
	// test fill empty lines short option
	char textIn[] =
		"\nvoid foo1(bool isFoo)\n"
		"{\n"
		"    a = 1;\n"
		"\n"
		"    if (isFoo)\n"
		"        b = 2;\n"
		"\n"
		"    c = 3;\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo)\n"
		"{\n"
		"    a = 1;\n"
		"    \n"
		"    if (isFoo)\n"
		"        b = 2;\n"
		"        \n"
		"    c = 3;\n"
		"}\n";
	char options[] = "-E";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(FillEmptyLinesTab)
{
	// test fill empty lines with tabs
	char textIn[] =
		"\nvoid foo1(bool isFoo)\n"
		"{\n"
		"    a = 1;\n"
		"\n"
		"    if (isFoo)\n"
		"        b = 2;\n"
		"    bool shouldFill = (newOperator != &AS_COLON\n"
		"                       && newOperator != &AS_PAREN);\n"
		"                       \n"
		"    c = 3;\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo)\n"
		"{\n"
		"	a = 1;\n"
		"	\n"
		"	if (isFoo)\n"
		"		b = 2;\n"
		"	bool shouldFill = (newOperator != &AS_COLON\n"
		"	                   && newOperator != &AS_PAREN);\n"
		"	                   \n"
		"	c = 3;\n"
		"}\n";
	char options[] = "fill-empty-lines, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(FillEmptyLinesForceTab)
{
	// test fill empty lines with force tabs
	char textIn[] =
		"\nvoid foo1(bool isFoo)\n"
		"{\n"
		"    a = 1;\n"
		"\n"
		"    if (isFoo)\n"
		"        b = 2;\n"
		"\n"
		"    bool shouldFill = (newOperator != &AS_COLON\n"
		"                       && newOperator != &AS_PAREN);\n"
		"                       \n"
		"    c = 3;\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo)\n"
		"{\n"
		"	a = 1;\n"
		"	\n"
		"	if (isFoo)\n"
		"		b = 2;\n"
		"		\n"
		"	bool shouldFill = (newOperator != &AS_COLON\n"
		"					   && newOperator != &AS_PAREN);\n"
		"					   \n"
		"	c = 3;\n"
		"}\n";
	char options[] = "fill-empty-lines, indent=force-tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
