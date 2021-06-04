/* SEARCH.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer nbchar, nbwrd, iwrd, ifac;
} sdp_;

#define sdp_1 sdp_

/* *** SOURCE FILE : SEARCH00.ORG   *** */


/*  *  SEARCH  *   INTEGER FUNCTION   25.6.86   E.MCLELLAN */

/*  PURPOSE     TO COMPARE SOURCE STRUCTURE TO A LIST OF */
/*              PRODUCTIONS AND TO DETERMINE WHICH PRODUCTION */
/*              IS 'MATCHED' BY THE SOURCE STRUCTURE */

/*  CALLING SEQUENCE */
/*              INTEGER= SEARCH (SOURCE,IADR,PRODCT,ERRPT) */

/*  ARGUMENTS   SOURCE   ARRAY CONTAINING SOURCE STRUCTURE. */
/*              IADR     ADDRESS OF FIRST ELEMENT. */
/*                       THE REMAINING ELEMENTS ARE STORED */
/*                       IN SUCCESSIVELY LOWER CORE LOCATIONS */
/*              PRODCT   ADDRESS OF THE FIRST ELEMENT OF THE */
/*                       FIRST PRODUCTION. THE REMAINING */
/*                       ELEMENTS ARE STORED IN SUCCESSIVELY */
/*                       HIGHER CORE LOCATIONS */
/*              ERRPT    ADDRESS OF THE PRODCT POSITION IN WHICH */
/*                       A MISMATCHED PRODUCTION WAS DETECTED */

/*  CALLED BY            GOPAT,INPAT,LARGES,PRO020,PRO021,RECOG, */
/*                       SSDEF,TSSMIL */

/*  SUBSIDIARIES         NONE */

integer search_(integer *source, integer *iadr, integer *prodct, integer *
	errpt)
{
    /* Initialized data */

    static integer z9999 = -1718026240;
    static integer zaaaa = -1431699456;
    static integer zcccc = -859045888;
    static integer zffff = -65536;

    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer i__, j, k;
    extern integer andf_(integer *, integer *);
    static integer iadsav, origin, subpat;



/*     IWRD: NO. OF BYTES PER WORD */


    /* Parameter adjustments */
    --prodct;
    --source;

    /* Function Body */

/* .... SAVE INITIAL STACK ADDRESS */
    iadsav = *iadr;
/* .... PRODCT ADDRESS */
    j = 1;
/* .... INITIAL VALUE OF ERRPT */
L5:
    k = *errpt;
/* .... INITIAL STACK ADDRESS */
    i__ = iadsav;
/* .... IS ADDRESS IN PRODCT A BREAK POINT ? */
    subpat = andf_(&prodct[j], &zffff);
    if (subpat == z9999) {
/* .... YES - STORE THE BASIC ADDRESS, INCREMENT PRODCT ADDRESS BY 1 */
	origin = j;
	++j;
    } else {
/* .... NOT A BREAK POINT - DECREASE STACK ADDRESS BY 2 */
/*                         DECREASE ERRPT BY 1 */
	i__ += -2;
	--k;
    }

/* .... NEW PRODUCTION */

L10:
    if (prodct[j] >= 0) {
/* .... COMPARE IF NEXT INFORMATION IS AN ARGUMENT, */
/*     IF SO CHANGE TO SEQUENTIAL MODE */
	if (prodct[j + 1] > 0) {
	    goto L50;
	}
/* ....COMPARE STACK AND PRODCT */
	subpat = andf_(&source[i__], &prodct[j]);
	if (source[i__] == subpat) {
/* .... PRODUCTION STILL OK, INCREMENT PRODCT BY 1 */
/*                          DECREMENT STACK BY 2 */
	    ++j;
	    i__ += -2;
/* .... DECREMENT ERRPT */
	    --k;
	} else {
/* .... MAINTAIN STACK ADDRESS CONSTANT, INCREMENT PRODCT BY 2 */
/*     AND SEARCH NEW PRODUCTION */
	    j += 2;
	}
	goto L10;

    } else {
/* .... IS PRODCT A PRODUCTION NUMBER */
	subpat = andf_(&prodct[j], &zffff);
	if (subpat == zcccc) {
	    goto L80;

/* .... IS IT A DISPLACEMENT */
	} else if (subpat == zaaaa) {
/* .... YES */
	    j = (prodct[j] - zaaaa) / sdp_1.iwrd;
	    j += origin;
	    goto L10;
	} else {
	    goto L5;
	}
    }

/* .... SEQUENTIAL SEARCHING */

L50:
    subpat = andf_(&source[i__], &prodct[j]);
    if (source[i__] == subpat) {
/* .... NEXT HIGHER PRODCT ADDRESS, NEXT LOWER STACK ADDRESS */
	++j;
	i__ += -2;
/* .... DECREMENT ERRPT */
	--k;
/* .... IS PRODCT A PRODUCTION NUMBER */
	subpat = andf_(&prodct[j], &zffff);
	if (subpat == zcccc) {
	    goto L80;
	} else {
	    goto L50;
	}
    } else {
/* .... SEARCHING FAILED. FINAL PROCESS. */
/*     SEARCH FOR NEXT FINAL PRODUCTION NUMBER */
L60:
	++j;
	subpat = andf_(&prodct[j], &zffff);
	if (subpat == zcccc) {
	    ++j;
	    goto L80;
	} else {
	    goto L60;
	}
    }

/* .... PRODUCTION NUMBER */

L80:
    ret_val = prodct[j] - zcccc;
    *errpt = k;
    return ret_val;
} /* search_ */

