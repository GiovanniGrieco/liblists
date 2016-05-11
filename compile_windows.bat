gcc -c -DBUILDING_EXAMPLE_DLL sllist.c -std=c11 -Wall -Wextra -Wpedantic -Werror -Wshadow -Wstrict-overflow -fno-strict-aliasing -Wno-missing-field-initializers
gcc -shared -o liblists.dll sllist.o -Wl,--out-implib,liblists.a

gcc -o sllist_examples\example_edit.exe sllist_examples\example_edit.c sllist_examples\common.c -L. -llists -std=c11 -Wall -Wextra -Wpedantic -Werror -Wshadow -Wstrict-overflow -fno-strict-aliasing -Wno-missing-field-initializers
gcc -o sllist_examples\example_gen3del1.exe sllist_examples\example_gen3del1.c sllist_examples\common.c -L. -llists -std=c11 -Wall -Wextra -Wpedantic -Werror -Wshadow -Wstrict-overflow -fno-strict-aliasing -Wno-missing-field-initializers
gcc -o sllist_examples\example_insert.exe sllist_examples\example_insert.c sllist_examples\common.c -L. -llists -std=c11 -Wall -Wextra -Wpedantic -Werror -Wshadow -Wstrict-overflow -fno-strict-aliasing -Wno-missing-field-initializers
gcc -o sllist_examples\example_invert.exe sllist_examples\example_invert.c sllist_examples\common.c -L. -llists -std=c11 -Wall -Wextra -Wpedantic -Werror -Wshadow -Wstrict-overflow -fno-strict-aliasing -Wno-missing-field-initializers
gcc -o sllist_examples\example_printList.exe sllist_examples\example_printList.c sllist_examples\common.c -L. -llists -std=c11 -Wall -Wextra -Wpedantic -Werror -Wshadow -Wstrict-overflow -fno-strict-aliasing -Wno-missing-field-initializers
gcc -o sllist_examples\example_search.exe sllist_examples\example_search.c sllist_examples\common.c -L. -llists -std=c11 -Wall -Wextra -Wpedantic -Werror -Wshadow -Wstrict-overflow -fno-strict-aliasing -Wno-missing-field-initializers
gcc -o sllist_examples\example_xchg.exe sllist_examples\example_xchg.c sllist_examples\common.c -L. -llists -std=c11 -Wall -Wextra -Wpedantic -Werror -Wshadow -Wstrict-overflow -fno-strict-aliasing -Wno-missing-field-initializers

mkdir objects
move *.o .\objects
move *.a .\objects
move sllist_examples\*.o .\objects

mkdir build
move sllist_examples\*.exe .\build
move liblists.dll .\build
pause