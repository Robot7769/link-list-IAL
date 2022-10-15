/**/
/*
 *  Předmět: Algoritmy (IAL) - FIT VUT v Brně
 *  Pokročilé testy pro příklad c201.c (Jednosměrně vázaný lineární seznam)
 *  Vytvořil: Martin Tuček, září 2005
 *  Úprava: Bohuslav Křena, říjen 2006
 */
#include "stdio.h"
#include "c201.h"
                                                         /* pracovní proměnné */
List TEMPLIST;
int obsah;
int MaxListLength2 = 100;                     /* Handles wrongly linked lists. */

/*******************************************************************************
 * Pomocné funkce usnadňující testování vlastní implementace.
 ******************************************************************************/

void print_elements_of_list(List SEZNAM)	{
/* Vytiskne seznam. */
	List temp_S=SEZNAM;
	int CurrListLength = 0;
	printf("-----------------");
	while ((temp_S.firstElement!=NULL) && (CurrListLength<MaxListLength2))	{
		printf("\n\t %d",temp_S.firstElement->data);
		if ((temp_S.firstElement==SEZNAM.activeElement) && (SEZNAM.activeElement!=NULL))
			printf("\t <= toto je aktivní prvek ");
		temp_S.firstElement=temp_S.firstElement->nextElement;
		CurrListLength++;
	}
    if (CurrListLength>=MaxListLength2){
        printf("\nList exceeded maximum length!");
    }
	printf("\n-----------------\n");
}

int use_copy(List *TL, int *obsah)	{
/* Ošetřuje použití operace List_GetValue. */
	int tmp;
	List_GetValue(TL,&tmp);
	if (!solved) {
		printf("Operace List_GetValue nebyla implementována!\n");
		return(FALSE);
	}
	else {
		if (error_flag)	{
			printf("Operace List_GetValue volala funkci Error.\n");
			error_flag=FALSE;
			return(FALSE);
		}
		else	{
			*obsah=tmp;
			printf("Operace List_GetValue vrací obsah %d.\n",tmp);
			return(TRUE);
		}
	}
}

int use_copy_first(List *TL, int *obsah)	{
/* Ošetřuje použití operace List_GetFirst. */
	int tmp;
	List_GetFirst(TL,&tmp);

	if (!solved)	{
		printf("Operace List_GetFirst nebyla implementována!\n");
		return(FALSE);
	}
	else {
		if (error_flag)	{
			printf("Operace List_GetFirst volala funkci Error.\n");
			error_flag=FALSE;
			return(FALSE);
		}
		else	{
			*obsah=tmp;
			printf("Operace List_GetFirst vrací obsah %d.\n",tmp);
			return(TRUE);
		}
	}
}

int use_active(List TL)	{
/* Ošetřuje použití operace List_IsActive. */
	int IsActive = List_IsActive(&TL);
	if (!solved)	{
		printf("Operace List_IsActive nebyla implementována!\n");
		return(FALSE);
	}
	else	{
		printf("Operace List_IsActive vrací %d.\n",IsActive);
		return(TRUE);
	}
}

/*
 * Následující funkce volané z vlastních testù uvedených ve funkci main
 * kontrolují, zda byly jednotlivé funkce implementovány,
 * případně vypisují aktuální stav pracovního seznamu TEMPLIST.
 */

int test_List_Init()	{

	solved=TRUE;
	List_Init(&TEMPLIST);
	if (!solved)	{
		printf("Operace List_Init nebyla implementovana \n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}

}

int test_List_GetValue()	{

	solved=TRUE;
	return(use_copy(&TEMPLIST,&obsah));

}

int test_List_GetFirst()	{

	solved=TRUE;
	return(use_copy_first(&TEMPLIST,&obsah));

}

int test_List_InsertFirst()	{

	solved=TRUE;
	List_InsertFirst(&TEMPLIST,obsah);
	if (!solved)	{
		printf("Operace List_InsertFirst nebyla implementována!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}

}

int test_List_First()	{

	solved=TRUE;
	List_First(&TEMPLIST);
	if (!solved)	{
		printf("Operace List_First nebyla implementována!\n");
		return(FALSE);
	}
	print_elements_of_list(TEMPLIST);
	return(TRUE);

}

int test_List_IsActive()	{

	solved=TRUE;
	return(use_active(TEMPLIST));

}

int test_List_Next()	{

	solved=TRUE;
	List_Next(&TEMPLIST);
	if (!solved)	{
		printf("Operace List_Next nebyla implementována!\n");
		return(FALSE);
	}
	print_elements_of_list(TEMPLIST);
	return(TRUE);

}

int test_List_SetValue()	{

	solved=TRUE;
	List_SetValue(&TEMPLIST,obsah);
	if (!solved)	{
		printf("Operace List_SetValue nebyla implementována!\n");
		return(FALSE);
	}
	print_elements_of_list(TEMPLIST);
	return(TRUE);

}

int test_List_DeleteFirst()	{

	solved=TRUE;
	List_DeleteFirst(&TEMPLIST);
	if (!solved)	{
		printf("Operace List_DeleteFirst() nebyla implementována!\n");
		return(FALSE);
	}
	print_elements_of_list(TEMPLIST);
	return(TRUE);

}

int test_List_DeleteAfter()	{

	solved=TRUE;
	List_DeleteAfter(&TEMPLIST);
	if (!solved)	{
		printf("Operace List_DeleteAfter() nebyla implementována!\n");
		return(FALSE);
	}
	print_elements_of_list(TEMPLIST);
	return(TRUE);

}

int test_List_InsertAfter()	{

	solved=TRUE;
	List_InsertAfter(&TEMPLIST,obsah);
	if (!solved){
		printf("Operace List_InsertAfter nebyla implementována!\n");
		return(FALSE);
	}
	print_elements_of_list(TEMPLIST);
	return(TRUE);

}

int test_List_Dispose() {

    solved=TRUE;
    List_Dispose(&TEMPLIST);
    if (!solved) {
        printf("Operace List_Dispose() nebyla implementována!\n");
        return(FALSE);
    }
    print_elements_of_list(TEMPLIST);
    return(TRUE);
}

/*******************************************************************************
 * POKROčILÉ TESTY
 * ---------------
 * Nejsou dostupné studentùm při řešení domácích úloh.
 * Za jejich úspěšné projítí získá student druhou část bodù za příklad.
 *
 ******************************************************************************/

int main(/*int argc, char *argv[]*/)	{

    printf("Jednosměrně vázaný lineární seznam\n");
    printf("==================================\n");

                            /* Testy 01 až 09 se shodují se základními testy. */

    printf("\n[TEST01]\n");
    printf("Inicializace seznamu\n");
    printf("~~~~~~~~~~~~~~~~~~~~\n");
    test_List_Init();

    printf("\n[TEST02]\n");
    printf("Pokus o volání List_GetFirst nad prázdným seznamem => chyba\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_GetFirst();

    printf("\n[TEST03]\n");
    printf("Zavoláme 4x operaci List_InsertFirst.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    obsah=1; test_List_InsertFirst();
    obsah=2; test_List_InsertFirst();
    obsah=3; test_List_InsertFirst();
    obsah=4; test_List_InsertFirst();

    printf("\n[TEST04]\n");
    printf("Seznam je neaktivní -- ověříme si to voláním funce List_IsActive.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_IsActive();

    printf("\n[TEST05]\n");
    printf("Otestujeme funkci List_First při neaktivním seznamu a funkci List_IsActive.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_First();
    test_List_IsActive();

    printf("\n[TEST06]\n");
    printf("Test funkce List_GetValue při aktivitě na prvním prvku\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_GetValue();

    printf("\n[TEST07]\n");
    printf("Test funkce List_Next -- voláme 3x, aktivita bude na posledním prvku.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_Next();
    test_List_Next();
    test_List_Next();
    test_List_IsActive();

    printf("\n[TEST08]\n");
    printf("Aktualizujeme obsah aktivního prvku.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    obsah=10;
    test_List_SetValue();
    test_List_IsActive();
    test_List_GetValue();

    printf("\n[TEST09]\n");
    printf("Provedeme ještě jednou List_Next -- aktivita se ztratí.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_Next();
    test_List_IsActive();

           /* Testy 10 až 14 testují chování operací nad neaktivním seznamem. */

    printf("\n[TEST10]\n");
    printf("Pokusíme se o aktualizaci při neaktivním seznamu => nic\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    obsah=100;
    test_List_SetValue();
    test_List_IsActive();

    printf("\n[TEST11]\n");
    printf("Pokus o List_GetValue při neaktivním seznamu => ošetřená chyba\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_GetValue();

    printf("\n[TEST12]\n");
    printf("Operace List_Next při neaktivním seznamu nesmí zhavarovat.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_Next();
    test_List_IsActive();

    printf("\n[TEST13]\n");
    printf("Použití operace List_GetFirst při neaktivním seznamu\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_GetFirst();

    printf("\n[TEST14]\n");
    printf("Vyzkoušíme operaci List_DeleteFirst při neaktivním seznamu,\n");
    printf("přičemž smazaný prvek zase vrátíme zpátky do seznamu.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_DeleteFirst();
    test_List_InsertFirst();
    test_List_IsActive();

                   /* Testy 15 až 23 se shodují se základními testy 10 až 18. */

    printf("\n[TEST10]\n");
    printf("Operace List_First nastaví aktivitu na první prvek.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_First();
    test_List_IsActive();

    printf("\n[TEST11]\n");
    printf("List_DeleteFirst aktivního prvku povede ke ztrátě aktivity.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_DeleteFirst();
    test_List_IsActive();

    printf("\n[TEST12]\n");
    printf("Užitím operací List_First a List_Next nastavíme aktivitu na konec seznamu.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_First();
    test_List_Next();
    test_List_Next();
    test_List_IsActive();

    printf("\n[TEST13]\n");
    printf("Operace List_DeleteAfter při aktivitě na posledním prvku nedělá nic.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_DeleteAfter();
    test_List_IsActive();

    printf("\n[TEST14]\n");
    printf("Nastavíme aktivitu na začátek a dvakrát zavoláme List_DeleteAfter.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_First();
    test_List_IsActive();
    test_List_DeleteAfter();
    test_List_DeleteAfter();
    test_List_IsActive();

    printf("\n[TEST15]\n");
    printf("Otestujeme List_InsertFirst při seznamu s jediným prvkem, nastavíme\n");
    printf("aktivitu na nově vložený prvek a opět posuneme aktivitu na konec\n");
    printf("seznamu.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    obsah=101;
    test_List_InsertFirst();
    test_List_First();
    test_List_Next();
    test_List_IsActive();

    printf("\n[TEST16]\n");
    printf("Operací List_InsertAfter vložíme nový prvek za poslední prvek seznamu.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    obsah=102;
    test_List_InsertAfter();
    test_List_IsActive();

    printf("\n[TEST17]\n");
    printf("Nastavíme aktivitu na první prvek seznamu a vyzkoušíme List_InsertAfter.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_First();
    obsah=103;
    test_List_InsertAfter();
    test_List_IsActive();

    printf("\n[TEST18]\n");
    printf("Otestujeme funkčnost operace List_Dispose.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_Dispose();

             /* Testy 24 až 30 testují chování operací nad prázdným seznamem. */

    printf("\n[TEST24]\n");
    printf("\n");
    printf("Následuje testování operací při prázdném seznamu\n");
    printf("================================================\n");
    test_List_IsActive();

    printf("\n[TEST25]\n");
    printf("List_DeleteFirst při prázdném seznamu => nic\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_DeleteFirst();

    printf("\n[TEST26]\n");
    printf("Test List_DeleteAfter při prázdném seznamu => nic \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
    test_List_DeleteAfter();

    printf("\n[TEST27]\n");
    printf("Ještě jednou List_Dispose => žádná změna\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_Dispose();

    printf("\n[TEST28]\n");
    printf("List_First ani List_InsertAfter nad prázdným seznamem nic nedělá.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_First();
    obsah=201;
    test_List_InsertAfter();

    printf("\n[TEST29]\n");
    printf("List_GetValue a List_GetFirst nad prázdným seznamem => ošetřená chyba\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_List_GetValue();
    test_List_GetFirst();

    printf("\n[TEST30]\n");
    printf("List_SetValue ani List_Next by neměly mít nad prázdným seznamem žádny efekt.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    obsah=202;
    test_List_SetValue();
    test_List_Next();
    test_List_IsActive();

    printf("\n----------------------- konec příkladu c201 -------------------------\n");


	return(0);
}
/**/