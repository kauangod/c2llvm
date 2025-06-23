define i32 @main() {
entry:
	%var1 = alloca i32, align 4
	%var2 = alloca float, align 4
	%var3 = alloca i32, align 4
	%0 = fadd float 0.0, 2.000000
	%1 = fadd float 0.0, 2.500000
	%2 = fmul float %0, %1
	store float %2, ptr %var2, align 4;
	%3 = load i32, i32* %var2, align 4
	%4 = add i32 0, 1
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
	%var4 = alloca i32, align 4
	%8 = add i32 0, 0
	store i32 %8, ptr %var4, align 4;
	%9 = add i32 0, 1
	store i32 %9, ptr %var3, align 4;
	%var5 = alloca i32, align 4
	br label %Label3

Label3:
	%10 = load i32, i32* %var4, align 4
	%11 = load i32, i32* %var1, align 4
	%12 = icmp slt i32 %10, %11
	br i1 %12, label %Label5, label %Label4
Label5:
		%13 = load i32, i32* %var3, align 4
		%14 = add i32 0, 3
		%15 = add i32 %13, %14
		store i32 %15, ptr %var3, align 4;
		%16 = load i32, i32* %var4, align 4
		%17 = add i32 0, 1
		%18 = add i32 %16, %17
		store i32 %18, ptr %var4, align 4;
		%19 = load i32, i32* %var3, align 4
		%20 = add i32 0, 2
		%21 = udiv i32 %19, %20
		store i32 %21, ptr %var5, align 4;
		%22 = load i32, i32* %var5, align 4
		%23 = add i32 0, 2
		%24 = mul i32 %22, %23
		%25 = load i32, i32* %var3, align 4
		%26 = icmp eq i32 %24, %25
		br i1 %26, label %Label7, label %Label6
Label7:
			%27 = load i32, i32* %var3, align 4
			%28 = call i32 (ptr, ...) @printf(ptr noundef @.str.0, i32 noundef %27)
			%29 = load i32, i32* %var3, align 4
			%30 = add i32 0, 3
			%31 = udiv i32 %29, %30
			store i32 %31, ptr %var5, align 4;
			%32 = load i32, i32* %var5, align 4
			%33 = add i32 0, 3
			%34 = mul i32 %32, %33
			%35 = load i32, i32* %var3, align 4
			%36 = icmp eq i32 %34, %35
			br i1 %36, label %Label9, label %Label8
Label9:
				%37 = load i32, i32* %var3, align 4
				%38 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %37)
			br label %Label8

Label8:
			%39 = load i32, i32* %var3, align 4
			%40 = add i32 0, 1
			%41 = add i32 %39, %40
			store i32 %41, ptr %var3, align 4;
		br label %Label10

Label6:
			%42 = load i32, i32* %var3, align 4
			%43 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %42)
br label %Label10

Label10:
br label %Label3

Label4:
	%var6 = alloca i8, align 1
	%44 = add i8 0, 97
	%45 = add i8 0, 1
	%46 = add i8 %44, %45
	store i8 %46, ptr %var6, align 1;
	%47 = load i8, i8* %var6, align 1
	%48 = sext i8 %47 to i32
%49 = call i32 (ptr, ...) @printf(ptr noundef @.str.3, i32 noundef %48)
	%50 = load i32, i32* %var1, align 4
	%51 = add i32 0, 25
	%52 = add i32 %50, %51
	%53 = call i32 (ptr, ...) @printf(ptr noundef @.str.4, i32 noundef %52)
	%54 = load i32, i32* %var3, align 4
	ret i32 %54

}




declare i32 @printf(ptr noundef, ...) #1
attributes #0 = { noinline nounwind optnone sspstrong uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
@.str.0 = private unnamed_addr constant [19 x i8] c"result é par: %d\0A\00", align 1
@.str.1 = private unnamed_addr constant [35 x i8] c"result é par e multiplo de 3: %d\0A\00", align 1
@.str.2 = private unnamed_addr constant [21 x i8] c"result é impar: %d\0A\00", align 1
@.str.3 = private unnamed_addr constant [15 x i8] c"testeChar: %c\0A\00", align 1
@.str.4 = private unnamed_addr constant [14 x i8] c"testeVar: %d\0A\00", align 1
