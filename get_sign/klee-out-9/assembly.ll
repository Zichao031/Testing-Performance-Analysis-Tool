; ModuleID = 'get_sign.bc'
source_filename = "get_sign.c"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx12.0.0"

@.str = private unnamed_addr constant [2 x i8] c"a\00", align 1

; Function Attrs: noinline nounwind optnone ssp uwtable
define i32 @get_sign(i32 %0) #0 !dbg !11 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  call void @llvm.dbg.declare(metadata i32* %3, metadata !15, metadata !DIExpression()), !dbg !16
  %4 = load i32, i32* %3, align 4, !dbg !17
  %5 = icmp eq i32 %4, 0, !dbg !19
  br i1 %5, label %6, label %7, !dbg !20

6:                                                ; preds = %1
  store i32 0, i32* %2, align 4, !dbg !21
  br label %12, !dbg !21

7:                                                ; preds = %1
  %8 = load i32, i32* %3, align 4, !dbg !22
  %9 = icmp slt i32 %8, 0, !dbg !24
  br i1 %9, label %10, label %11, !dbg !25

10:                                               ; preds = %7
  store i32 -1, i32* %2, align 4, !dbg !26
  br label %12, !dbg !26

11:                                               ; preds = %7
  store i32 1, i32* %2, align 4, !dbg !27
  br label %12, !dbg !27

12:                                               ; preds = %11, %10, %6
  %13 = load i32, i32* %2, align 4, !dbg !28
  ret i32 %13, !dbg !28
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: noinline nounwind optnone ssp uwtable
define i32 @main() #0 !dbg !29 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  call void @llvm.dbg.declare(metadata i32* %2, metadata !32, metadata !DIExpression()), !dbg !33
  %3 = bitcast i32* %2 to i8*, !dbg !34
  call void @klee_make_symbolic(i8* %3, i64 4, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i64 0, i64 0)), !dbg !35
  %4 = load i32, i32* %2, align 4, !dbg !36
  %5 = call i32 @get_sign(i32 %4), !dbg !37
  ret i32 %5, !dbg !38
}

declare void @klee_make_symbolic(i8*, i64, i8*) #2

attributes #0 = { noinline nounwind optnone ssp uwtable "darwin-stkchk-strong-link" "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "darwin-stkchk-strong-link" "frame-pointer"="all" "no-trapping-math"="true" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4, !5, !6}
!llvm.dbg.cu = !{!7}
!llvm.ident = !{!10}

!0 = !{i32 2, !"SDK Version", [2 x i32] [i32 12, i32 3]}
!1 = !{i32 7, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{i32 7, !"PIC Level", i32 2}
!5 = !{i32 7, !"uwtable", i32 1}
!6 = !{i32 7, !"frame-pointer", i32 2}
!7 = distinct !DICompileUnit(language: DW_LANG_C99, file: !8, producer: "Apple clang version 13.1.6 (clang-1316.0.21.2.5)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !9, splitDebugInlining: false, nameTableKind: None, sysroot: "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk", sdk: "MacOSX.sdk")
!8 = !DIFile(filename: "get_sign.c", directory: "/Users/xiaozichao/klee_/get_sign")
!9 = !{}
!10 = !{!"Apple clang version 13.1.6 (clang-1316.0.21.2.5)"}
!11 = distinct !DISubprogram(name: "get_sign", scope: !8, file: !8, line: 7, type: !12, scopeLine: 7, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !7, retainedNodes: !9)
!12 = !DISubroutineType(types: !13)
!13 = !{!14, !14}
!14 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!15 = !DILocalVariable(name: "x", arg: 1, scope: !11, file: !8, line: 7, type: !14)
!16 = !DILocation(line: 7, column: 18, scope: !11)
!17 = !DILocation(line: 8, column: 7, scope: !18)
!18 = distinct !DILexicalBlock(scope: !11, file: !8, line: 8, column: 7)
!19 = !DILocation(line: 8, column: 9, scope: !18)
!20 = !DILocation(line: 8, column: 7, scope: !11)
!21 = !DILocation(line: 9, column: 6, scope: !18)
!22 = !DILocation(line: 11, column: 7, scope: !23)
!23 = distinct !DILexicalBlock(scope: !11, file: !8, line: 11, column: 7)
!24 = !DILocation(line: 11, column: 9, scope: !23)
!25 = !DILocation(line: 11, column: 7, scope: !11)
!26 = !DILocation(line: 12, column: 6, scope: !23)
!27 = !DILocation(line: 14, column: 6, scope: !23)
!28 = !DILocation(line: 15, column: 1, scope: !11)
!29 = distinct !DISubprogram(name: "main", scope: !8, file: !8, line: 17, type: !30, scopeLine: 17, spFlags: DISPFlagDefinition, unit: !7, retainedNodes: !9)
!30 = !DISubroutineType(types: !31)
!31 = !{!14}
!32 = !DILocalVariable(name: "a", scope: !29, file: !8, line: 18, type: !14)
!33 = !DILocation(line: 18, column: 7, scope: !29)
!34 = !DILocation(line: 19, column: 22, scope: !29)
!35 = !DILocation(line: 19, column: 3, scope: !29)
!36 = !DILocation(line: 20, column: 19, scope: !29)
!37 = !DILocation(line: 20, column: 10, scope: !29)
!38 = !DILocation(line: 20, column: 3, scope: !29)
