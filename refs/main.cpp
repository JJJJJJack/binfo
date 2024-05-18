void showHeader(IMAGE_DOS_HEADER dosHeader) {
    UINT64 offset = 0;

    printf("%llX: e_magic: %X\n", offset, dosHeader.e_magic);
    offset += sizeof(dosHeader.e_magic);
    printf("%llX: e_cblp: %X\n", offset, dosHeader.e_cblp);
    offset += sizeof(dosHeader.e_cblp);
    printf("%llX: e_cp: %X\n", offset, dosHeader.e_cp);
    offset += sizeof(dosHeader.e_cp);
    printf("%llX: e_crlc: %X\n", offset, dosHeader.e_crlc);
    offset += sizeof(dosHeader.e_crlc);
    printf("%llX: e_cparhdr: %X\n", offset, dosHeader.e_cparhdr);
    offset += sizeof(dosHeader.e_cparhdr);
    printf("%llX: e_minalloc: %X\n", offset, dosHeader.e_minalloc);
    offset += sizeof(dosHeader.e_minalloc);
    printf("%llX: e_maxalloc: %X\n", offset, dosHeader.e_maxalloc);
    offset += sizeof(dosHeader.e_maxalloc);
    printf("%llX: e_ss: %X\n", offset, dosHeader.e_ss);
    offset += sizeof(dosHeader.e_ss);
    printf("%llX: e_sp: %X\n", offset, dosHeader.e_sp);
    offset += sizeof(dosHeader.e_sp);
    printf("%llX: e_csum: %X\n", offset, dosHeader.e_csum);
    offset += sizeof(dosHeader.e_csum);
    printf("%llX: e_ip: %X\n", offset, dosHeader.e_ip);
    offset += sizeof(dosHeader.e_ip);
    printf("%llX: e_cs: %X\n", offset, dosHeader.e_cs);
    offset += sizeof(dosHeader.e_cs);
    printf("%llX: e_lfarlc: %X\n", offset, dosHeader.e_lfarlc);
    offset += sizeof(dosHeader.e_lfarlc);
    printf("%llX: e_ovno: %X\n", offset, dosHeader.e_ovno);
    offset += sizeof(dosHeader.e_ovno);

    printf("e_res:\n");
    for (int i = 0; i < 4; i++) {
        printf("%llX: \t%X\n", offset, dosHeader.e_res[i]);
        offset += sizeof(dosHeader.e_res[i]);
    }

    printf("%llX: e_oemid: %X\n", offset, dosHeader.e_oemid);
    offset += sizeof(dosHeader.e_oemid);
    printf("%llX: e_oeminfo: %X\n", offset, dosHeader.e_oeminfo);
    offset += sizeof(dosHeader.e_oeminfo);

    printf("e_res2:\n");
    for (int i = 0; i < 10; i++) {
        printf("%llX: \t%X\n", offset, dosHeader.e_res2[i]);
        offset += sizeof(dosHeader.e_res2[i]);
    }

    printf("%llX: e_lfanew: %X\n", offset, dosHeader.e_lfanew);
}

void showNtHeader(IMAGE_NT_HEADERS ntHeaders) {
    printf("Signature: %X\n", ntHeaders.Signature);
    printf("FileHeader:\n");
    printf("\tMachine: %X\n", ntHeaders.FileHeader.Machine);
    printf("\tNumberOfSections: %X\n", ntHeaders.FileHeader.NumberOfSections);
    printf("\tTimeDateStamp: %X\n", ntHeaders.FileHeader.TimeDateStamp);
    printf("\tPointerToSymbolTable: %X\n",
           ntHeaders.FileHeader.PointerToSymbolTable);
    printf("\tNumberOfSymbols: %X\n", ntHeaders.FileHeader.NumberOfSymbols);
    printf("\tSizeOfOptionalHeader: %X\n",
           ntHeaders.FileHeader.SizeOfOptionalHeader);
    printf("\tCharacteristics: %X\n", ntHeaders.FileHeader.Characteristics);

    printf("OptionalHeader:\n");
    printf("\tMagic: %X\n", ntHeaders.OptionalHeader.Magic);
    printf("\tMajorLinkerVersion: %X\n",
           ntHeaders.OptionalHeader.MajorLinkerVersion);
    printf("\tMinorLinkerVersion: %X\n",
           ntHeaders.OptionalHeader.MinorLinkerVersion);
    printf("\tSizeOfCode: %X\n", ntHeaders.OptionalHeader.SizeOfCode);
    printf("\tSizeOfInitializedData: %X\n",
           ntHeaders.OptionalHeader.SizeOfInitializedData);
    printf("\tSizeOfUninitializedData: %X\n",
           ntHeaders.OptionalHeader.SizeOfUninitializedData);
    printf("\tAddressOfEntryPoint: %X\n",
           ntHeaders.OptionalHeader.AddressOfEntryPoint);
    printf("\tBaseOfCode: %X\n", ntHeaders.OptionalHeader.BaseOfCode);
    // printf("\tBaseOfData: %X\n", ntHeaders.OptionalHeader.BaseOfData);
    printf("\tImageBase: %X\n", ntHeaders.OptionalHeader.ImageBase);
    printf("\tSectionAlignment: %X\n",
           ntHeaders.OptionalHeader.SectionAlignment);
    printf("\tFileAlignment: %X\n", ntHeaders.OptionalHeader.FileAlignment);
    printf("\tMajorOperatingSystemVersion: %X\n",
           ntHeaders.OptionalHeader.MajorOperatingSystemVersion);
    printf("\tMinorOperatingSystemVersion: %X\n",
           ntHeaders.OptionalHeader.MinorOperatingSystemVersion);
    printf("\tMajorImageVersion: %X\n",
           ntHeaders.OptionalHeader.MajorImageVersion);
    printf("\tMinorImageVersion: %X\n",
           ntHeaders.OptionalHeader.MinorImageVersion);
    printf("\tMajorSubsystemVersion: %X\n",
           ntHeaders.OptionalHeader.MajorSubsystemVersion);
    printf("\tMinorSubsystemVersion: %X\n",
           ntHeaders.OptionalHeader.MinorSubsystemVersion);
    printf("\tWin32VersionValue: %X\n",
           ntHeaders.OptionalHeader.Win32VersionValue);
    printf("\tSizeOfImage: %X\n", ntHeaders.OptionalHeader.SizeOfImage);
    printf("\tSizeOfHeaders: %X\n", ntHeaders.OptionalHeader.SizeOfHeaders);
    printf("\tCheckSum: %X\n", ntHeaders.OptionalHeader.CheckSum);
    printf("\tSubsystem: %X\n", ntHeaders.OptionalHeader.Subsystem);
    printf("\tDllCharacteristics: %X\n",
           ntHeaders.OptionalHeader.DllCharacteristics);
    printf("\tSizeOfStackReserve: %X\n",
           ntHeaders.OptionalHeader.SizeOfStackReserve);
    printf("\tSizeOfStackCommit: %X\n",
           ntHeaders.OptionalHeader.SizeOfStackCommit);
    printf("\tSizeOfHeapReserve: %X\n",
           ntHeaders.OptionalHeader.SizeOfHeapReserve);
    printf("\tSizeOfHeapCommit: %X\n",
           ntHeaders.OptionalHeader.SizeOfHeapCommit);
    printf("\tLoaderFlags: %X\n", ntHeaders.OptionalHeader.LoaderFlags);
    printf("\tNumberOfRvaAndSizes: %X\n",
           ntHeaders.OptionalHeader.NumberOfRvaAndSizes);

    printf("DataDirectory:\n");
    for (int i = 0; i < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++) {
        printf("\tVirtualAddress: %X\n",
               ntHeaders.OptionalHeader.DataDirectory[i].VirtualAddress);
        printf("\tSize: %X\n", ntHeaders.OptionalHeader.DataDirectory[i].Size);
    }
}
