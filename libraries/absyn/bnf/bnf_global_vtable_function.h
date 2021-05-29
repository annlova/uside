//
// Created by Anton on 2021-05-29.
//

#ifndef USIDE_LIBRARIES_ABSYN_BNF_BNF_GLOBAL_VTABLE_FUNCTION_H
#define USIDE_LIBRARIES_ABSYN_BNF_BNF_GLOBAL_VTABLE_FUNCTION_H

#include "cat.h"
#include "def.h"
#include "grammar.h"
#include "int_list.h"
#include "item.h"
#include "label.h"
#include "label_id.h"
#include "list_def.h"
#include "list_ident.h"
#include "list_int_list.h"
#include "list_integer.h"
#include "list_item.h"
#include "list_prof_item.h"
#include "list_rhs.h"
#include "list_string.h"
#include "minimum_size.h"
#include "prof_item.h"
#include "reg.h"
#include "rhs.h"

namespace absyn::bnf {

    enum AbsynBnfClasses : int {
        CAT_SQUARE = 0,
        CAT_IDENT,
        DEF_LABEL,
        DEF_LINE_COMMENT,
        DEF_BLOCK_COMMENT,
        DEF_INTERNAL,
        DEF_TOKEN,
        DEF_POSITION_TOKEN,
        DEF_ENTRY_POINTS,
        DEF_SEPARATOR,
        DEF_TERMINATOR,
        DEF_COERCIONS,
        DEF_RULES,
        DEF_LAYOUT,
        DEF_LAYOUT_STOP,
        DEF_LAYOUT_TOP_LEVEL,
        GRAMMAR_LIST_DEF,
        INT_LIST_LIST_INTEGER,
        ITEM_STRING,
        ITEM_CAT,
        LABEL_LABEL_ID,
        LABEL_LABEL_ID_LIST_PROF_ITEM,
        LABEL_DOUBLE_LABEL_ID_LIST_PROF_ITEM,
        LABEL_ID_IDENT,
        LABEL_ID_UNDERSCORE,
        LABEL_ID_SQUARE_BRACKETS,
        LABEL_ID_BRACKETS_COLON,
        LABEL_ID_BRACKETS_COLON_SQUARE,
        LIST_DEF_EPSILON,
        LIST_DEF_LIST,
        LIST_IDENT_IDENT,
        LIST_IDENT_IDENT_LIST,
        LIST_INT_LIST_EPSILON,
        LIST_INT_LIST_INT_LIST,
        LIST_INT_LIST_INT_LIST_LIST,
        LIST_INTEGER_EMPTY,
        LIST_INTEGER_INTEGER,
        LIST_INTEGER_INTEGER_LIST,
        LIST_ITEM_EPSILON,
        LIST_ITEM_ITEM_LIST,
        LIST_PROF_ITEM_PROF_ITEM,
        LIST_PROF_ITEM_LIST,
        LIST_RHSRHS,
        LIST_RHS_LIST,
        LIST_STRING_STRING,
        LIST_STRING_LIST,
        MINIMUM_SIZE_NONEMPTY,
        MINIMUM_SIZE_EPSILON,
        PROF_ITEM_BRACKETS,
        REG_REG,
        REG_OR,
        REG_MINUS,
        REG_DOUBLE_REG,
        REG_STAR,
        REG_PLUS,
        REG_QUESTION,
        REG_EPS,
        REG_REAL_CHAR,
        REG_SQUARE_STRING,
        REG_CURLY_STRING,
        REG_DIGIT,
        REG_LETTER,
        REG_UPPER,
        REG_LOWER,
        REG_CHAR,
        RHS_LIST_ITEM,
    };

    inline void* getVTablePtr(AbsynBnfClasses bnfClass) {
        switch (bnfClass) {
            case CAT_SQUARE: {
                CatSquare c;
                return getVTable(&c);
            }
            case CAT_IDENT: {
                CatIdent c;
                return getVTable(&c);
            }
            case DEF_LABEL: {
				DefLabel c;
				return getVTable(&c);
			}
            case DEF_LINE_COMMENT: {
				DefLineComment c;
				return getVTable(&c);
			}
            case DEF_BLOCK_COMMENT: {
				DefBlockComment c;
				return getVTable(&c);
			}
            case DEF_INTERNAL: {
				DefInternal c;
				return getVTable(&c);
			}
            case DEF_TOKEN: {
				DefToken c;
				return getVTable(&c);
			}
            case DEF_POSITION_TOKEN: {
				DefPositionToken c;
				return getVTable(&c);
			}
            case DEF_ENTRY_POINTS: {
				DefEntryPoints c;
				return getVTable(&c);
			}
            case DEF_SEPARATOR: {
				DefSeparator c;
				return getVTable(&c);
			}
            case DEF_TERMINATOR: {
				DefTerminator c;
				return getVTable(&c);
			}
            case DEF_COERCIONS: {
				DefCoercions c;
				return getVTable(&c);
			}
            case DEF_RULES: {
				DefRules c;
				return getVTable(&c);
			}
            case DEF_LAYOUT: {
				DefLayout c;
				return getVTable(&c);
			}
            case DEF_LAYOUT_STOP: {
				DefLayoutStop c;
				return getVTable(&c);
			}
            case DEF_LAYOUT_TOP_LEVEL: {
				DefLayoutTopLevel c;
				return getVTable(&c);
			}
            case GRAMMAR_LIST_DEF: {
				GrammarListDef c;
				return getVTable(&c);
			}
            case INT_LIST_LIST_INTEGER: {
				IntListListInteger c;
				return getVTable(&c);
			}
            case ITEM_STRING: {
				ItemString c;
				return getVTable(&c);
			}
            case ITEM_CAT: {
				ItemCat c;
				return getVTable(&c);
			}
            case LABEL_LABEL_ID: {
				LabelLabelId c;
				return getVTable(&c);
			}
            case LABEL_LABEL_ID_LIST_PROF_ITEM: {
				LabelLabelIdListProfItem c;
				return getVTable(&c);
			}
            case LABEL_DOUBLE_LABEL_ID_LIST_PROF_ITEM: {
				LabelDoubleLabelIdListProfItem c;
				return getVTable(&c);
			}
            case LABEL_ID_IDENT: {
				LabelIdIdent c;
				return getVTable(&c);
			}
            case LABEL_ID_UNDERSCORE: {
				LabelIdUnderscore c;
				return getVTable(&c);
			}
            case LABEL_ID_SQUARE_BRACKETS: {
				LabelIdSquareBrackets c;
				return getVTable(&c);
			}
            case LABEL_ID_BRACKETS_COLON: {
				LabelIdBracketsColon c;
				return getVTable(&c);
			}
            case LABEL_ID_BRACKETS_COLON_SQUARE: {
				LabelIdBracketsColonSquare c;
				return getVTable(&c);
			}
            case LIST_DEF_EPSILON: {
				ListDefEpsilon c;
				return getVTable(&c);
			}
            case LIST_DEF_LIST: {
				ListDefList c;
				return getVTable(&c);
			}
            case LIST_IDENT_IDENT: {
				ListIdentIdent c;
				return getVTable(&c);
			}
            case LIST_IDENT_IDENT_LIST: {
				ListIdentIdentList c;
				return getVTable(&c);
			}
            case LIST_INT_LIST_EPSILON: {
				ListIntListEpsilon c;
				return getVTable(&c);
			}
            case LIST_INT_LIST_INT_LIST: {
				ListIntListIntList c;
				return getVTable(&c);
			}
            case LIST_INT_LIST_INT_LIST_LIST: {
				ListIntListIntListList c;
				return getVTable(&c);
			}
            case LIST_INTEGER_EMPTY: {
				ListIntegerEmpty c;
				return getVTable(&c);
			}
            case LIST_INTEGER_INTEGER: {
				ListIntegerInteger c;
				return getVTable(&c);
			}
            case LIST_INTEGER_INTEGER_LIST: {
				ListIntegerIntegerList c;
				return getVTable(&c);
			}
            case LIST_ITEM_EPSILON: {
				ListItemEpsilon c;
				return getVTable(&c);
			}
            case LIST_ITEM_ITEM_LIST: {
				ListItemItemList c;
				return getVTable(&c);
			}
            case LIST_PROF_ITEM_PROF_ITEM: {
				ListProfItemProfItem c;
				return getVTable(&c);
			}
            case LIST_PROF_ITEM_LIST: {
				ListProfItemList c;
				return getVTable(&c);
			}
            case LIST_RHSRHS: {
				ListRHSRHS c;
				return getVTable(&c);
			}
            case LIST_RHS_LIST: {
				ListRHSList c;
				return getVTable(&c);
			}
            case LIST_STRING_STRING: {
				ListStringString c;
				return getVTable(&c);
			}
            case LIST_STRING_LIST: {
				ListStringList c;
				return getVTable(&c);
			}
            case MINIMUM_SIZE_NONEMPTY: {
				MinimumSizeNonempty c;
				return getVTable(&c);
			}
            case MINIMUM_SIZE_EPSILON: {
				MinimumSizeEpsilon c;
				return getVTable(&c);
			}
            case PROF_ITEM_BRACKETS: {
				ProfItemBrackets c;
				return getVTable(&c);
			}
            case REG_REG: {
				RegReg c;
				return getVTable(&c);
			}
            case REG_OR: {
				RegOr c;
				return getVTable(&c);
			}
            case REG_MINUS: {
				RegMinus c;
				return getVTable(&c);
			}
            case REG_DOUBLE_REG: {
				RegDoubleReg c;
				return getVTable(&c);
			}
            case REG_STAR: {
				RegStar c;
				return getVTable(&c);
			}
            case REG_PLUS: {
				RegPlus c;
				return getVTable(&c);
			}
            case REG_QUESTION: {
				RegQuestion c;
				return getVTable(&c);
			}
            case REG_EPS: {
				RegEps c;
				return getVTable(&c);
			}
            case REG_REAL_CHAR: {
				RegRealChar c;
				return getVTable(&c);
			}
            case REG_SQUARE_STRING: {
				RegSquareString c;
				return getVTable(&c);
			}
            case REG_CURLY_STRING: {
				RegCurlyString c;
				return getVTable(&c);
			}
            case REG_DIGIT: {
				RegDigit c;
				return getVTable(&c);
			}
            case REG_LETTER: {
				RegLetter c;
				return getVTable(&c);
			}
            case REG_UPPER: {
				RegUpper c;
				return getVTable(&c);
			}
            case REG_LOWER: {
				RegLower c;
				return getVTable(&c);
			}
            case REG_CHAR: {
				RegChar c;
				return getVTable(&c);
			}
            case RHS_LIST_ITEM: {
				RHSListItem c;
				return getVTable(&c);
			}
            default:
                return nullptr; // TODO: Some sort of error handling
        }
    }
}

#endif //USIDE_LIBRARIES_ABSYN_BNF_BNF_GLOBAL_VTABLE_FUNCTION_H
