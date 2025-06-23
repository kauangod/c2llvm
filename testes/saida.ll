define i32 @main() {
entry:
	%var1 = alloca i32, align 4
	%var2 = alloca float, align 4
	%var3 = alloca i32, align 4
	%var4 = alloca i32, align 4
	%var5 = alloca float, align 4
	%var6 = alloca i8, align 1
	%var7 = alloca i32, align 4
	%0 = fadd float 0.0, 2.000000
	%1 = fadd float 0.0, 2.500000
	%2 = fmul float %0, %1
	store float %2, ptr %var2, align 4;
	%3 = load i32, i32* %var2, align 4
	%4 = add i32 0, 5
	%5 = icmp sgt i32 %3, %4
	br i1 %5, label %Label1, label %Label0
Label1:
	%6 = add i32 0, 10
	store i32 %6, ptr %var1, align 4;
	br label %Label2

Label0:
	%7 = add i32 0, 3
	store i32 %7, ptr %var1, align 4;
br label %Label2

Label2:
	%8 = load i32, i32* %var1, align 4
	%9 = call i32 (ptr, ...) @printf(ptr noundef @.str.0, i32 noundef %8)
	%var8 = alloca i32, align 4
	%10 = add i32 0, 0
	store i32 %10, ptr %var8, align 4;
	%11 = add i32 0, 1
	store i32 %11, ptr %var3, align 4;
	%var9 = alloca i32, align 4
	br label %Label3

Label3:
	%12 = load i32, i32* %var8, align 4
	%13 = load i32, i32* %var1, align 4
	%14 = icmp slt i32 %12, %13
	br i1 %14, label %Label5, label %Label4
Label5:
	%15 = load i32, i32* %var3, align 4
	%16 = add i32 0, 3
	%17 = add i32 %15, %16
	store i32 %17, ptr %var3, align 4;
	%18 = load i32, i32* %var8, align 4
	%19 = add i32 0, 1
	%20 = add i32 %18, %19
	store i32 %20, ptr %var8, align 4;
	%21 = load i32, i32* %var3, align 4
	%22 = add i32 0, 2
	%23 = udiv i32 %21, %22
	store i32 %23, ptr %var9, align 4;
	%24 = load i32, i32* %var9, align 4
	%25 = add i32 0, 2
	%26 = mul i32 %24, %25
	%27 = load i32, i32* %var3, align 4
	%28 = icmp eq i32 %26, %27
	br i1 %28, label %Label7, label %Label6
Label7:
	%29 = load i32, i32* %var3, align 4
	%30 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %29)
	%31 = load i32, i32* %var3, align 4
	%32 = add i32 0, 3
	%33 = udiv i32 %31, %32
	store i32 %33, ptr %var9, align 4;
	%34 = load i32, i32* %var9, align 4
	%35 = add i32 0, 3
	%36 = mul i32 %34, %35
	%37 = load i32, i32* %var3, align 4
	%38 = icmp eq i32 %36, %37
	br i1 %38, label %Label9, label %Label8
Label9:
	%39 = load i32, i32* %var3, align 4
	%40 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %39)
	br label %Label8

Label8:
	%41 = load i32, i32* %var3, align 4
	%42 = add i32 0, 1
	%43 = add i32 %41, %42
	store i32 %43, ptr %var3, align 4;
	br label %Label10

Label6:
	%44 = load i32, i32* %var3, align 4
	%45 = call i32 (ptr, ...) @printf(ptr noundef @.str.3, i32 noundef %44)
br label %Label10

Label10:
br label %Label3

Label4:
	%var10 = alloca i8, align 1
	%46 = add i8 0, 97
	%47 = add i8 0, 1
	%48 = add i8 %46, %47
	store i8 %48, ptr %var10, align 1;
	%49 = load i8, i8* %var10, align 1
	%50 = sext i8 %49 to i32
%51 = call i32 (ptr, ...) @printf(ptr noundef @.str.4, i32 noundef %50)
	%52 = load i32, i32* %var1, align 4
	%53 = add i32 0, 25
	%54 = add i32 %52, %53
	%55 = call i32 (ptr, ...) @printf(ptr noundef @.str.5, i32 noundef %54)
	%56 = call i32 (ptr, ...) @printf(ptr noundef @.str.6)
	%57 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str.7, ptr noundef %var1)
	%58 = add i32 0, 1
	store i32 %58, ptr %var3, align 4;
	%59 = add i32 0, 0
	store i32 %59, ptr %var8, align 4;
	br label %Label11

Label11:
	%60 = load i32, i32* %var8, align 4
	%61 = load i32, i32* %var1, align 4
	%62 = icmp slt i32 %60, %61
	br i1 %62, label %Label13, label %Label12
Label13:
	%63 = load i32, i32* %var3, align 4
	%64 = add i32 0, 2
	%65 = mul i32 %63, %64
	store i32 %65, ptr %var3, align 4;
	%66 = load i32, i32* %var8, align 4
	%67 = add i32 0, 1
	%68 = add i32 %66, %67
	store i32 %68, ptr %var8, align 4;
br label %Label11

Label12:
	%69 = load i32, i32* %var1, align 4
	%70 = call i32 (ptr, ...) @printf(ptr noundef @.str.8, i32 noundef %69)
	%71 = load i32, i32* %var3, align 4
	%72 = call i32 (ptr, ...) @printf(ptr noundef @.str.9, i32 noundef %71)
	%73 = add i8 0, 97
	%74 = add i8 0, 257
	%75 = add i8 %73, %74
	%76 = sext i8 %75 to i32
%77 = call i32 (ptr, ...) @printf(ptr noundef @.str.10, i32 noundef %76)
	%78 = load i32, i32* %var3, align 4
	ret i32 %78

}




declare i32 @printf(ptr noundef, ...) #1
declare i32 @__isoc99_scanf(ptr noundef, ...) #1

@.str.0 = private unnamed_addr constant [16 x i8] c"testeVar é %d\0A\00", align 1
@.str.1 = private unnamed_addr constant [19 x i8] c"result é par: %d\0A\00", align 1
@.str.2 = private unnamed_addr constant [35 x i8] c"result é par e multiplo de 3: %d\0A\00", align 1
@.str.3 = private unnamed_addr constant [21 x i8] c"result é impar: %d\0A\00", align 1
@.str.4 = private unnamed_addr constant [15 x i8] c"testeChar: %c\0A\00", align 1
@.str.5 = private unnamed_addr constant [14 x i8] c"testeVar: %d\0A\00", align 1
@.str.6 = private unnamed_addr constant [58 x i8] c"insira qual potência de dois maior que zero você quer: \00", align 1
@.str.7 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.8 = private unnamed_addr constant [5 x i8] c"2^%d\00", align 1
@.str.9 = private unnamed_addr constant [7 x i8] c" = %d\0A\00", align 1
@.str.10 = private unnamed_addr constant [28 x i8] c"teste overflow de char: %c\0A\00", align 1
