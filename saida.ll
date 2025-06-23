define i32 @main() {
entry:
	%var1 = alloca i8, align 1
	%var2 = alloca i32, align 4
	%var3 = alloca i32, align 4
	%var4 = alloca float, align 4
	%var5 = alloca i32, align 4
	%var6 = alloca i32, align 4
	%var7 = alloca float, align 4
	%var8 = alloca i8, align 1
	%var9 = alloca i32, align 4
	%0 = fadd float 0.0, 2.000000
	%1 = fadd float 0.0, 2.500000
	%2 = fmul float %0, %1
	store float %2, ptr %var4, align 4;
	%3 = add i8 0, 97
	store i8 %3, ptr %var1, align 1;
	%4 = load i32, i32* %var4, align 4
	%5 = add i32 0, 3
	%6 = icmp sgt i32 %4, %5
	br i1 %6, label %Label1, label %Label0
Label1:
	%7 = add i32 0, 10
	store i32 %7, ptr %var3, align 4;
	br label %Label2

Label0:
	%8 = add i32 0, 3
	store i32 %8, ptr %var3, align 4;
br label %Label2

Label2:
	%9 = add i32 0, 0
	store i32 %9, ptr %var2, align 4;
	%10 = add i32 0, 1
	store i32 %10, ptr %var5, align 4;
	br label %Label3

Label3:
	%11 = load i32, i32* %var2, align 4
	%12 = load i32, i32* %var3, align 4
	%13 = icmp slt i32 %11, %12
	br i1 %13, label %Label5, label %Label4
Label5:
	%14 = load i32, i32* %var5, align 4
	%15 = add i32 0, 2
	%16 = mul i32 %14, %15
	store i32 %16, ptr %var5, align 4;
	%17 = load i32, i32* %var2, align 4
	%18 = add i32 0, 1
	%19 = add i32 %17, %18
	store i32 %19, ptr %var2, align 4;
br label %Label3

Label4:
	%20 = add i8 0, 97
	%21 = add i8 0, 1
	%22 = add i8 %20, %21
	store i8 %22, ptr %var1, align 1;
	%23 = load i8, i8* %var1, align 1
	%24 = sext i8 %23 to i32
%25 = call i32 (ptr, ...) @printf(ptr noundef @.str.0, i32 noundef %24)
	%26 = load i32, i32* %var3, align 4
	%27 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %26)
	%28 = load float, float* %var4, align 4
	%29 = fpext float %28 to double
%30 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, double noundef %29)
	%31 = load i32, i32* %var5, align 4
	%32 = call i32 (ptr, ...) @printf(ptr noundef @.str.3, i32 noundef %31)
	%33 = load i32, i32* %var2, align 4
	%34 = call i32 (ptr, ...) @printf(ptr noundef @.str.4, i32 noundef %33)
	%35 = add i8 0, 97
	%36 = add i8 0, 1
	%37 = add i8 %35, %36
	store i8 %37, ptr %var1, align 1;
	%38 = load i8, i8* %var1, align 1
	%39 = sext i8 %38 to i32
%40 = call i32 (ptr, ...) @printf(ptr noundef @.str.5, i32 noundef %39)
	%41 = load i32, i32* %var3, align 4
	%42 = call i32 (ptr, ...) @printf(ptr noundef @.str.6, i32 noundef %41)
	%43 = load float, float* %var4, align 4
	%44 = fpext float %43 to double
%45 = call i32 (ptr, ...) @printf(ptr noundef @.str.7, double noundef %44)
	%46 = load i32, i32* %var5, align 4
	%47 = call i32 (ptr, ...) @printf(ptr noundef @.str.8, i32 noundef %46)
	%48 = load i32, i32* %var2, align 4
	%49 = call i32 (ptr, ...) @printf(ptr noundef @.str.9, i32 noundef %48)
	%50 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str.10, ptr noundef %var6)
	%51 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str.11, ptr noundef %var7)
	%52 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str.12, ptr noundef %var8)
	%53 = load i32, i32* %var5, align 4
	ret i32 %53

}




declare i32 @printf(ptr noundef, ...) #1
declare i32 @__isoc99_scanf(ptr noundef, ...) #1

attributes #0 = { noinline nounwind optnone sspstrong uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
@.str.0 = private unnamed_addr constant [15 x i8] c"testeChar: %c\0A\00", align 1
@.str.1 = private unnamed_addr constant [14 x i8] c"testeVar: %d\0A\00", align 1
@.str.2 = private unnamed_addr constant [12 x i8] c"testeF: %f\0A\00", align 1
@.str.3 = private unnamed_addr constant [12 x i8] c"result: %d\0A\00", align 1
@.str.4 = private unnamed_addr constant [7 x i8] c"i: %d\0A\00", align 1
@.str.5 = private unnamed_addr constant [15 x i8] c"testeChar: %c\0A\00", align 1
@.str.6 = private unnamed_addr constant [14 x i8] c"testeVar: %d\0A\00", align 1
@.str.7 = private unnamed_addr constant [12 x i8] c"testeF: %f\0A\00", align 1
@.str.8 = private unnamed_addr constant [12 x i8] c"result: %d\0A\00", align 1
@.str.9 = private unnamed_addr constant [7 x i8] c"i: %d\0A\00", align 1
@.str.10 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.11 = private unnamed_addr constant [3 x i8] c"%f\00", align 1
@.str.12 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
