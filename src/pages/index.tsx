import { SignInButton, SignOutButton, SignUpButton, useUser } from "@clerk/nextjs";
import Head from "next/head";
import Link from "next/link";


import { api } from "~/utils/api";




export default function Home() {
  const hello = api.post.hello.useQuery({ text: "from tRPC" });

  const user = useUser();

  return (
    <>
      <Head>
        <title>Create T3 App</title>
        <meta name="description" content="Generated by create-t3-app" />
        <link rel="icon" href="/favicon.ico" />
      </Head>
      <main> 
 

     <div>
      {!user.isSignedIn && <SignInButton />}
      {!!user.isSignedIn && <SignOutButton />}
     </div>

      </main>
    </>
  );
}
