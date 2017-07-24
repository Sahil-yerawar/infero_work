; ModuleID = 'sample_program.c'
source_filename = "sample_program.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind uwtable
define i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %t = alloca i32, align 4
  %a = alloca [11 x i32], align 16
  %i = alloca i32, align 4
  %i1 = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  store i32 0, i32* %t, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i32, i32* %i, align 4
  %cmp = icmp slt i32 %0, 10
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %1 = load i32, i32* %i, align 4
  %inc = add nsw i32 %1, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  store i32 0, i32* %i1, align 4
  br label %for.cond2

for.cond2:                                        ; preds = %for.inc9, %for.end
  %2 = load i32, i32* %i1, align 4
  %cmp3 = icmp slt i32 %2, 10
  br i1 %cmp3, label %for.body4, label %for.end11

for.body4:                                        ; preds = %for.cond2
  %3 = load i32, i32* %t, align 4
  %inc5 = add nsw i32 %3, 1
  store i32 %inc5, i32* %t, align 4
  %4 = load i32, i32* %i1, align 4
  %mul = mul nsw i32 %4, 2
  %cmp6 = icmp slt i32 %mul, 15
  br i1 %cmp6, label %if.then, label %if.else

if.then:                                          ; preds = %for.body4
  %5 = load i32, i32* %t, align 4
  %add = add nsw i32 %5, 2
  store i32 %add, i32* %t, align 4
  %6 = load i32, i32* %t, align 4
  %sub = sub nsw i32 %6, 1
  store i32 %sub, i32* %t, align 4
  br label %for.end11

if.else:                                          ; preds = %for.body4
  %7 = load i32, i32* %t, align 4
  %add7 = add nsw i32 %7, 2
  store i32 %add7, i32* %t, align 4
  br label %if.end

if.end:                                           ; preds = %if.else
  %8 = load i32, i32* %t, align 4
  %sub8 = sub nsw i32 %8, 1
  store i32 %sub8, i32* %t, align 4
  br label %for.inc9

for.inc9:                                         ; preds = %if.end
  %9 = load i32, i32* %i1, align 4
  %inc10 = add nsw i32 %9, 1
  store i32 %inc10, i32* %i1, align 4
  br label %for.cond2

for.end11:                                        ; preds = %if.then, %for.cond2
  ret i32 0
}

attributes #0 = { noinline nounwind uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 4.0.1 (http://llvm.org/git/clang.git 21fe7e8f8ab44b67238af7bf9ba9d8afdf0c0e2c) (http://llvm.org/git/llvm.git f34c300665523e385deaf0b7e32cb1ffe78f5e33)"}
